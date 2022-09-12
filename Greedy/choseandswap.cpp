#include<bits/stdc++.h>
using namespace std;

string swapAllOccurences(char ch1, char ch2, string s) {
    for(int i=0; i<s.length(); i++)  {
        if(s[i] == ch1)
            s[i] = ch2;
        else if(s[i] == ch2)
            s[i] = ch1;
    }
    return s;
}
 
 // O(nlgn) time and O(|number of distinct characters|) space
string chooseandswap(string s) {
    set<char> lst;
    for(int i=0; i<s.length(); i++) {
        lst.insert(s[i]);
    }
    for(int i=0; i<s.length() && !lst.empty(); i++) {
        if(lst.find(s[i]) != lst.end()) {
            if(s[i] != *lst.begin()) {
                return swapAllOccurences(s[i], *lst.begin(), s);
            }
            lst.erase(s[i]);
        }
    }
    return s;
}