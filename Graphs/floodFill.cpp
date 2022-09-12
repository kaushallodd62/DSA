#include <bits/stdc++.h>
using namespace std;

bool isSafe (vector<vector<int>>& image, int sr, int sc) {
    return (sr >= 0 && sc >= 0 && sr < image.size() && sc < image[sr].size());
}

void floodFillAux (vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
    image[sr][sc] = newColor;

    if (isSafe (image, sr-1, sc) && image[sr-1][sc] == oldColor)
        floodFillAux (image, sr-1, sc, newColor, oldColor);

    if (isSafe (image, sr, sc-1) && image[sr][sc-1] == oldColor)
        floodFillAux (image, sr, sc-1, newColor, oldColor);

    if (isSafe (image, sr+1, sc) && image[sr+1][sc] == oldColor)
        floodFillAux (image, sr+1, sc, newColor, oldColor);

    if (isSafe (image, sr, sc+1) && image[sr][sc+1] == oldColor)
        floodFillAux (image, sr, sc+1, newColor, oldColor);

    return;
}

// DFS solution
vector<vector<int>> floodFill (vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (isSafe (image, sr, sc) && image[sr][sc] != newColor)
        floodFillAux (image, sr, sc, newColor, image[sr][sc]);
    return image;
}

// BFS Solution
vector<vector<int>> floodFill (vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (!isSafe (image, sr, sc) || oldColor == newColor)
        return image;
    
    queue<pair<int, int>> q;
    pair<int, int> pos;
    q.push({sr, sc});
    while (!q.empty()) {
        pos = q.front();
        q.pop();

        image[pos.first][pos.second] = newColor;

        if (isSafe (image, pos.first-1, pos.second) && image[pos.first-1][pos.second] == oldColor)
            q.push({pos.first-1, pos.second});

        if (isSafe (image, pos.first, pos.second-1) && image[pos.first][pos.second-1] == oldColor)
            q.push({pos.first, pos.second-1});

        if (isSafe (image, pos.first+1, pos.second) && image[pos.first+1][pos.second] == oldColor)
            q.push({pos.first+1, pos.second});

        if (isSafe (image, pos.first, pos.second+1) && image[pos.first][pos.second+1] == oldColor)
            q.push({pos.first, pos.second+1});
        
    }
    return image;
}