//  Shortest Path in Binary Matrix
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        int drow[] = {-1,0,1,0,1,-1,-1,1};
        int dcol[] = {0,1,0,-1,1,-1,1,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            vis[row][col] =1;
            q.pop();
            if(row == n-1 && col == n-1){
                return dis;
            }
            for(int i=0;i<8;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n && grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    q.push({{nrow,ncol},dis+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return -1;
    }
    // tc-> 0(N*N)
    // sc->0(N*N)
};