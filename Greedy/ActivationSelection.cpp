#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> meetings;
    for(int i=0; i<n; i++) {
        meetings.push_back({start[i], end[i]});
    }
    sort(meetings.begin(), meetings.end(), cmp);
    int res = 1, prev = 0;
    for(int i=1; i<n; i++) {
        if(meetings[i].first > meetings[prev].second) {
            res++;
            prev = i;
        }
    }
    return res;
}