// Number of Enclaves || Multi-source BFS
// count the no's of lands(1) for going out of the boundary  
// return the count of lands from which u cant reach the boundary
#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:
    void dfs(int row,int col,vector<pair<int,int>>&vec,vector<vector<int>>&visited,vector<vector<int>>& grid,int row0,int col0){
        visited[row][col] =1;
        vec.push_back({row-row0,col-col0});
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,vec,visited,grid,row0,col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<pair<int,int>>vec;
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(i,j,vec,visited,grid,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
// tc-> 0(N*M*log(n*M)) where logN*M is set length at max it store all the element
// sc ->0(N*M)