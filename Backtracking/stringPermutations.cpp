#include<bits/stdc++.h>
using namespace std;

void find_permutation_aux(string s, string perm, vector<string>& res, unordered_set<int> visit) {
    if(perm.length() == s.length()) {
        if(find(res.begin(), res.end(), perm) == res.end())
            res.push_back(perm);
        return;
    }
    for(int i=0; i<s.length(); i++) {
        if(visit.find(i) == visit.end()) {
            perm.push_back(s[i]);
            visit.insert(i);
            find_permutation_aux(s, perm, res, visit);

            //backtracking
            perm.pop_back();
            visit.erase(i);
        }
    }
}

void permute(string s, int pos, vector<string>& res) {
    if(pos == s.length()) {
        if(find(res.begin(), res.end(), s) == res.end())
            res.push_back(s);
        return;
    }
    for(int i=pos; i<s.length(); i++) {
        swap(s[pos], s[i]);
        permute(s, pos+1, res);
        swap(s[pos], s[i]);
    }
}

// method 1 backtracking (solved by myself)
vector<string> find_permutation(string s) {
    vector<string> res;
    string perm;
    unordered_set<int> visit;
    find_permutation_aux(s, perm, res, visit);
    sort(res.begin(), res.end());
    return res;
}

// method 2 backtracking (gfg)
vector<string> find_permutation(string s) {
    vector<string> res;
    permute(s, 0, res);
    sort(res.begin(), res.end());
    return res;
}

// method 3 using next_permutation(), which modifies s to give the next lexicographic perm of s. If s is the last lexicographic perm of the string, then it return false
vector<string> find_permutation(string s) {
    vector<string> res;
    sort(s.begin(), s.end());
    do {
        res.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    return res;
}