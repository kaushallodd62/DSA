#include<bits/stdc++.h>
using namespace std;

class cell {
    public:
        int x, y, dist;
        cell() {
            dist = 0;
        }
        cell(int x_pos, int y_pos, int d) {
            x = x_pos;
            y = y_pos;
            dist = d;
        }
};

bool isInside(int x, int y, int N) {
    return (x > 0 && x <= N && y > 0 && y <= N);
}

// BFS traversal of all possible new knight positions.
int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
    vector<pair<int, int>> moves = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}, {-1, 2}, {-2, 1}};
    bool traversed[N+1][N+1] = {false};
    queue<cell> q;
    q.push(cell(KnightPos[0], KnightPos[1], 0));
    traversed[KnightPos[0]][KnightPos[1]] = true;
    cell curr;
    while(!q.empty()) {
        curr = q.front();
        q.pop();

        if(curr.x == TargetPos[0] && curr.y == TargetPos[1])
            return curr.dist;

        for(int i=0; i<8; i++) {
            int new_x = curr.x + moves[i].first;
            int new_y = curr.y + moves[i].second;
            if(isInside(new_x, new_y, N) && !traversed[new_x][new_y]) {
                q.push(cell(new_x, new_y, curr.dist+1));
                traversed[new_x][new_y] = true;
            }
        }
    }
}