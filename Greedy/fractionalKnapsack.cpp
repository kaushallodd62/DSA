#include<bits/stdc++.h>
using namespace std;

class Item {
    public: 
        int value, weight;
};

static bool cmp(Item& a, Item& b) {
    double a_ratio = (double)a.value/a.weight;
    double b_ratio = (double)b.value/b.weight;
    return a_ratio > b_ratio;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr+n, cmp);
    double profit = 0;
    for(int i=0; i<n; i++) {
        if(arr[i].weight < W) {
            profit += arr[i].value;
            W -= arr[i].weight;
        }
        else {
            profit += W * (double)arr[i].value/arr[i].weight;
            break;
        }
    }
    return profit;
}