#include<bits/stdc++.h>
using namespace std;

void wordBreakUtil(vector<string>& soln, vector<string>& dict, string s, string ans, int index) {
    if(index == s.length()) {
        ans.erase(ans.begin());
        soln.push_back(ans);
    }
    string sub;
    for(int i=index; i<s.length(); i++) {
        sub.push_back(s[i]);
        if(find(dict.begin(), dict.end(), sub) != dict.end()) {
            ans.append(" " + sub);
            wordBreakUtil(soln, dict, s, ans, i+1);
            ans.erase(ans.length() - (sub.length() + 1));
        }
    }
}

vector<string> wordBreak(int n, vector<string>& dict, string s) {
    vector<string> soln;
    string sub, ans;
    wordBreakUtil(soln, dict, s, ans, 0);
    return soln;
}