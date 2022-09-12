#include<bits/stdc++.h>
using namespace std;

// function checks if str2 is different than str1 by just one letter
bool checkValid (string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    int count = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i])
            count++;
    }
    return count == 1;
}

// BFS solution O(N^2 * M) - where N is the size of wordList and M is the size of a string
int ladderLength (string beginWord, string endWord, vector<string>& wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return 0;

    if (beginWord == endWord)
        return 1;
    
    queue<string> q;
    unordered_set<string> visited;
    int level = 1;

    q.push(beginWord);
    visited.insert(beginWord);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string curr = q.front();
            q.pop();

            for (int i = 0; i < wordList.size(); i++) {
                if (visited.find(wordList[i]) == visited.end() && checkValid(curr, wordList[i])) {
                    if (wordList[i] == endWord)
                        return level + 1;
                    q.push (wordList[i]);
                    visited.insert (wordList[i]);
                }
            }
        }
        level++;
    }
    return 0;
}

// Bi-directional BFS (do BFS from startWord and endWord)
int ladderLength (string beginWord, string endWord, vector<string>& wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
    return 0;

    if (beginWord == endWord)
        return 1;

    queue<string> leftQ, rightQ;
    unordered_set<string> leftS, rightS;
    int leftLevel = 1, rightLevel = 1;

    leftQ.push(beginWord);
    rightQ.push(endWord);
    leftS.insert(beginWord);
    rightS.insert(endWord);

    while (!leftQ.empty() && !rightQ.empty()) {
        int leftQSize = leftQ.size(), rightQSize = rightQ.size();

        // left side BFS
        for (int i = 0; i < leftQSize; i++) {
            string curr = leftQ.front();
            leftQ.pop();

            for (int i = 0; i < wordList.size(); i++) {
                if (leftS.find(wordList[i]) == leftS.end() && checkValid(curr, wordList[i])) {
                    if (wordList[i] == endWord)
                        return leftLevel + 1;
                    if (rightS.find(wordList[i]) != rightS.end()) {
                        return leftLevel + rightLevel;
                    }
                    leftQ.push (wordList[i]);
                    leftS.insert (wordList[i]);
                }
            }
        }
        leftLevel++;

        // right side BFS
        for (int i = 0; i < rightQSize; i++) {
            string curr = rightQ.front();
            rightQ.pop();

            for (int i = 0; i < wordList.size(); i++) {
                if (rightS.find(wordList[i]) == rightS.end() && checkValid(curr, wordList[i])) {
                    if (wordList[i] == endWord)
                        return rightLevel + 1;
                    if (leftS.find(wordList[i]) != leftS.end()) {
                        return leftLevel + rightLevel;
                    }
                    rightQ.push (wordList[i]);
                    rightS.insert (wordList[i]);
                }
            }
        }
        rightLevel++;
    }
    return 0;
}