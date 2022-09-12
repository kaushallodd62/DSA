#include<bits/stdc++.h>
using namespace std;

class Job {
    public:
        int profit, dead;

        bool operator()(Job& a, Job& b) {
            return a.profit < b.profit;
        }

        bool cmp(Job& a, Job& b) {
            return a.dead < b.dead;
        }
};

vector<int> JobScheduling(Job arr[], int n) {
    vector<int> res;
    priority_queue<Job, vector<Job>, Job> pq;
    sort(arr, arr+n, Job::cmp);
    for(int i=n-1; i>=0; i--) {
        int slots;
        if(i == 0)
            slots  = arr[i].dead;
        else
            slots = arr[i].dead - arr[i-1].dead;
        pq.push(arr[i]);
        while(slots > 0 && !pq.empty()) {
            Job j = pq.top();
            pq.pop();
            slots--;
            res.push_back(j.profit);
        }
    }
    return {(int)res.size(), accumulate(res.begin(), res.end(), 0)};
}