#include<bits/stdc++.h>
using namespace std;
#define N 9

bool isInside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool isValid(int grid[N][N], int x, int y, int val) {
    for(int i=0; i<N; i++) {
        if(grid[i][y] == val)
            return false;
        if(grid[x][i] == val)
            return false;
    }
    int start_x = x - x%3;
    int start_y = y - y%3;
    for(int i=start_x; i<start_x + N/3; i++) {
        for(int j=start_y; j<start_y + N/3; j++) {
            if(grid[i][j] == val)
                return false;
        }
    }
    return true;
}

bool solveSudokuHelper(int grid[N][N], int x, int y) {
    if(x == N-1 && y == N)
        return true;
    if(!isInside(x, y)) {
        return solveSudokuHelper(grid, x+1, 0);
    }
    if(grid[x][y] != 0)
        return solveSudokuHelper(grid, x, y+1);
    for(int val=1; val<=N; val++) {
        if(isValid(grid, x, y, val)) {
            grid[x][y] = val;
            if(solveSudokuHelper(grid, x, y+1))
                return true;
            grid[x][y] = 0;
        }
    }
    return false;
}

// method 1. solveSudokuHelper() contains the position too, so we recursively keep track of unfilled positions.
bool SolveSudoku(int grid[N][N]) {
    return solveSudokuHelper(grid, 0, 0);
}

// solution 2. only difference is that here the double for loop finds the next unfilled position. this does extra unnecessary traversals.
bool SolveSudoku(int grid[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!grid[i][j]) {
                for(int val=1; val<=N; val++) {
                    if(isValid(grid, i, j, val)) {
                        grid[i][j] = val;
                        if(SolveSudoku(grid))
                            return true;
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}