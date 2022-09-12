#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int i=0, n=s.length();
            while(i<n/2 && s[i] == s[n-i-1])
                i++;
            return i == n/2;
        }

        void helper(vector<vector<string>>& res, vector<string>& v, string s, int index) {
            if(index == s.length()) {
                res.push_back(v);
                return;
            }
            string sub;
            for(int i=index; i<s.length(); i++) {
                sub.push_back(s[i]);
                if(isPalindrome(sub)) {
                    v.push_back(sub);
                    helper(res, v, s, i+1);
                    // backtracking
                    v.pop_back();
                }
            }
        }

        vector<vector<string>> allPalindromicPerms(string s) {
            vector<vector<string>> res;
            vector<string> v;
            helper(res, v, s, 0);
            return res;
        }
};