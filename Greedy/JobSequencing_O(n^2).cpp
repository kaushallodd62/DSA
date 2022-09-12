#include<bits/stdc++.h>
using namespace std;

class Job {
    public:
        int id;
        int dead;
        int profit;
};

static bool cmp(Job& a, Job& b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    unordered_set<int> slots;
    sort(arr, arr+n, cmp);
    int profit = 0, jobs = 0;
    for(int i=0; i<n; i++) {
        for(int j=min(n, arr[i].dead); j>0; j--) {
            if(slots.find(j) == slots.end()) {
                slots.insert(j);
                profit += arr[i].profit;
                jobs++;
                break;  
            }
        }
    }
    return {jobs, profit};
}