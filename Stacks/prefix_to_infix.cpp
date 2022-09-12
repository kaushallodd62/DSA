#include<bits/stdc++.h>
using namespace std;

string prefixToInfix(string s) {
    int len = s.size();
    stack<string> stck;
    for(int i=len-1; i>=0; i--) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            string str="";
            str.push_back(s[i]);
            stck.push(str);
        }
        else {
            string op1 = stck.top();
            stck.pop();
            string op2 = stck.top();
            stck.pop();

            string expr = "(" + op1 + s[i] + op2 + ")";
            stck.push(expr);
        }
    }
    return stck.top();
}

int main() {
    string s = "*-A/BC-/AKL";
    cout << prefixToInfix(s) << endl;
    return 0;
}