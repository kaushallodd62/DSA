#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& m, int n, pair<int, int> pos) {
    if(pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < n && m[pos.first][pos.second])
        return true;
    return false;
}

void findPathAux(vector<vector<int>>& m, int n, pair<int, int> pos, string& s, vector<string>& soln, vector<vector<int>>& traversed) {
    traversed[pos.first][pos.second] = 1;
    if(pos.first == n-1 && pos.second == n-1)
        soln.push_back(s);
    
    if(isSafe(m, n, {pos.first+1, pos.second}) && !traversed[pos.first+1][pos.second]) {
        s.push_back('D');
        findPathAux(m, n, {pos.first+1, pos.second}, s, soln, traversed);
    }
    if(isSafe(m, n, {pos.first, pos.second+1}) && !traversed[pos.first][pos.second+1]) {
        s.push_back('R');
        findPathAux(m, n, {pos.first, pos.second+1}, s, soln, traversed);
    }
    if(isSafe(m, n, {pos.first-1, pos.second}) && !traversed[pos.first-1][pos.second]) {
        s.push_back('U');
        findPathAux(m, n, {pos.first-1, pos.second}, s, soln, traversed);
    }
    if(isSafe(m, n, {pos.first, pos.second-1}) && !traversed[pos.first][pos.second-1]) {
        s.push_back('L');
        findPathAux(m, n, {pos.first, pos.second-1}, s, soln, traversed);
    }

    traversed[pos.first][pos.second] = 0;   
    if(!s.empty())
        s.pop_back();
}

vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> soln;
    if(m[0][0] == 0 || m[n-1][n-1] == 0)
        return soln;
    vector<vector<int>> traversed(n, vector<int>(n, 0));
    string s = "";
    findPathAux(m, n, {0, 0}, s, soln, traversed);
    return soln;
}

int main() {
    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    vector<string> s = findPath(m, n);
    for(auto& x: s) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}