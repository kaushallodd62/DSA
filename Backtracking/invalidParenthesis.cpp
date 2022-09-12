#include<bits/stdc++.h>
using namespace std;

bool canConsider(stack<char> stk, char ch) {
    return ch == '(' || (ch == ')' && !stk.empty());
}

void Util(vector<string>& soln, stack<char> stk, string s, string ans, int index, int count, int& min_count) {
    if(index == s.length()) {
        if(stk.empty()) {
            if(soln.empty())
                min_count = count;
            if(find(soln.begin(), soln.end(), ans) == soln.end())
                soln.push_back(ans);
        }
        return;
    }
    for(int i=index; i<s.length(); i++) {
        // if the character is not a parenthesis
        if(s[i] != '(' && s[i] != ')') {
            ans.push_back(s[i]);
            Util(soln, stk, s, ans, i+1, count, min_count);
            continue;
        }
        
        // consider the parenthesis if you can consider it
        if(canConsider(stk, s[i])) {
            if(s[i] == '(')
                stk.push(s[i]);
            else
                stk.pop();
            ans.push_back(s[i]);
            Util(soln, stk, s, ans, i+1, count, min_count);
            
            // backtracking
            ans.pop_back();
            if(s[i] == ')')
                stk.push('(');
            else
                stk.pop();
        }
        
        // don't consider the parenthesis (delete the parenthesis)
        count++;
        if(soln.empty() || count <= min_count)
            Util(soln, stk, s, ans, i+1, count, min_count);
        else
            return;
    }
}

// Backtracking Solution
vector<string> removeInvalidParentheses(string s) {
    vector<string> soln;
    stack<char> stck;
    int min_count = 0;
    Util(soln, stck, s, "", 0, 0, min_count);
    return soln;
}

bool isParenthesis(char ch) {
    return ch == '(' || ch == ')';
}

bool isValidString(string s) {
    int cnt = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(')
            cnt++;
        else if(s[i] == ')')
            cnt--;
        if(cnt < 0)
            return false;
    }
    return cnt == 0;
}

// BFS Solution
vector<string> removeInvalidParenthesesBFS(string s) {
    vector<string> soln;
    if(s.empty()) {
        soln.push_back("");
        return soln;
    }
    queue<string> q;
    unordered_set<string> visited;
    q.push(s);
    visited.insert(s);
    bool level = false;
    while(!q.empty()) {
        string str = q.front();
        q.pop();
        if(isValidString(str)) {
            soln.push_back(str);
            level = true;
        }
        if(level)
            continue;
        for(int i=0; i<str.length(); i++) {
            if(!isParenthesis(str[i]))
                continue;
            string temp = str.substr(0, i) + str.substr(i+1);
            if(visited.find(temp) == visited.end()) {
                q.push(temp);
                visited.insert(temp);
            }
        }
    }
    return soln;
}