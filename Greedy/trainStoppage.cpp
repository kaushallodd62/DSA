#include<bits/stdc++.h>
using namespace std;

class Train {
    public:
        int arrivalTime, departureTime, platformNumber;

        Train (int aT, int dT, int pN) {
            this->arrivalTime = aT;
            this->departureTime = dT;
            this->platformNumber = pN;
        }
};


int maxStops (int n, int m, const vector<Train>& trains) {
    // per platform schedules
    vector<pair<int, int>> schedules[n+1];
    for (int i = 0; i < m; i++) {
        schedules[trains[i].platformNumber].push_back({trains[i].departureTime, trains[i].arrivalTime});
    }

    // sorting the vector of trains in each platform by their dept time
    for (int i = 0; i <= n; i++) {
        sort (schedules[i].begin(), schedules[i].end());
    }

    // greedily stopping trains based on first to depart
    int res = 0;
    for (int i = 1; i <= n; i++) {
        // continuing if there are no scheduled trains on this plarform
        if (schedules[i].size() == 0)
            continue;

        // first train for each platform will always be selected
        int prevTrain = 0;
        res++;
        for (int j = 1; j < schedules[i].size(); j++) {
            if (schedules[i][prevTrain].first <= schedules[i][j].second) {
                prevTrain = j;
                res++;
            }
        }
    }

    return res;
}

int main () {
    int n = 2, m = 5;
    vector<Train> trains = {
        Train (1000, 1030, 1),
        Train (1010, 1020, 1),
        Train (1025, 1040, 1),
        Train (1130, 1145, 2),
        Train (1130, 1140, 2)
    };

    cout << maxStops (n, m, trains) << endl;
    return 0;   
}