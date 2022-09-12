#include<bits/stdc++.h>
using namespace std;

bool isInside(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool knightsTourDFS(vector<vector<int>>& soln, int N, vector<int>& dx, vector<int>& dy, pair<int, int> pos, int count) {
    soln[pos.first][pos.second] = count;
    if(count == N*N)
        return true;
    for(int i=0; i<8; i++) {
        int x = pos.first + dx[i];
        int y = pos.second + dy[i];
        if(isInside(x, y, N) && !soln[x][y]) {
            if(knightsTourDFS(soln, N, dx, dy, {x, y}, ++count))
                return true;
            else
                count--;
        }
    }
    soln[pos.first][pos.second] = 0;
    return false;
}

void printSolution(vector<vector<int>>& soln, int N) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << soln[i][j] << " ";
        }
        cout << endl;
    }
}

void knightsTour(int N) {
    vector<vector<int>> soln(N, vector<int>(N, 0));
    vector<int> dx = { 2, 1, -1, -2, -2, -1, 1, 2 };
    vector<int> dy = { 1, 2, 2, 1, -1, -2, -2, -1 };
    if(!knightsTourDFS(soln, N, dx, dy, {0, 0}, 1)) {
        cout << "Solution doesn't exist." << endl;
        return;
    }
    printSolution(soln, N);
    return;
}

int main() {
    knightsTour(8);
    return 0;
}