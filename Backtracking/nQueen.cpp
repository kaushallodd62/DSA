#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& soln, int N) {
    // check if position is in the board
    if(x > 0 && x <= N && y > 0 && y <= N) {
        // checking the horizontal line for a queen
        for(int i=1; i<=y; i++) {
            if(soln[x][i])
                return false;
        }

        // checking the upper diagnol on left side
        for(int posx = x, posy = y; posx > 0 && posy > 0; posx--, posy--) {
           if(soln[posx][posy])
                return false;
        }

        // checking the lower diagnol on left side
        for(int posx = x, posy = y; posx <= N && posy > 0; posx++, posy--) {
            if(soln[posx][posy])
                return false;
        }

        // There is no need to check vertical line as we will fill only one queen column wise
        // There is no need to check right side diagnols as we are filling queens left to right, and there will be no queens on the right side
        return true;
    }
    // else if the position is not in the board, return false
    return false;
}

void nQueenUtil(vector<vector<int>>& soln, vector<vector<int>>& ans, int N, int y) {
    if(y > N) {
        vector<int> v;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(soln[j][i])
                    v.push_back(j);
            }
        }
        ans.push_back(v);
        return;
    }
    for(int i=1; i<=N; i++) {
        if(isSafe(i, y, soln, N)) {
            soln[i][y] = 1;
            nQueenUtil(soln, ans, N, y+1);
            soln[i][y] = 0;
        }
    }
}

vector<vector<int>> nQueen(int N) {
    vector<vector<int>> soln(N+1, vector<int>(N+1, 0)), ans;
    vector<int> v;
    nQueenUtil(soln, ans, N, 1);
    return ans;
}