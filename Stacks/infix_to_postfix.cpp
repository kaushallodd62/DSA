#include<bits/stdc++.h>
using namespace std;

int prec(char ch) {
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '(' || ch == ')')
        return 0;
    else return -1;
}

string infixToPostfix(string s) {
    stack<char> stck;
    string ans = "";
    for(auto& ch: s) {
        int ch_val = prec(ch);
        if(ch_val < 0)
            ans.push_back(ch);
        else if(ch == '(')
            stck.push(ch);
        else if (ch == ')') {
            while(stck.top() != '(') {
                ans.push_back(stck.top());
                stck.pop();
            }
            stck.pop();
        }
        else {
            while(!stck.empty() && ch_val <= prec(stck.top())) {
                if(ch_val == 3 && stck.top() == '^')
                    break;
                ans.push_back(stck.top());
                stck.pop();
            }
            stck.push(ch);
        }
    }

    while(!stck.empty()) {
        ans.push_back(stck.top());
        stck.pop();
    }

    return ans;
}