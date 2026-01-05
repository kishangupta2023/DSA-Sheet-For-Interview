// Surrounded Regions | Replace 0's with X's
// Given a matrix mat of size N x M where every element is either 'O' or 'X'.
// Replace all 'O' with 'X' that are surrounded by 'X'.
// A'O' (or a set of 'O') is considered to be by surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> & mat,int drow[],int dcol[]){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        // chech for 4 sides
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                dfs(nrow,ncol,vis,mat,drow,dcol);
            }
        }
    }
    public:
    vector<vector<char>> fill(int n ,int m, vector<vector<char>> mat){
        vector<vector<int>>vis(n,vector<int>(m,0));
        int drow[] ={-1,0,1,0};
        int dcol[] ={0,1,0,-1};
        //traverse first row and last row
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && mat[0][j] =='O'){
                dfs(0,j,vis,mat,drow,dcol);
            }
            // last row 
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1,j,vis,mat,drow,dcol);
            }
        }
        // traverse first col and last col
        for(int i=0;i<n;i++){
            //first row
            if(!vis[i][0] && mat[i][0] =='O'){
                dfs(i,0,vis,mat,drow,dcol);
            }
            // last row 
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i,m-1,vis,mat,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }

};
//


// with bfs 
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
            }
            if(board[i][m-1] == 'O'){
                q.push({i,m-1});
            }
        }
        for(int i=1;i<m-1;i++){
            if(board[0][i] == 'O'){
                q.push({0,i});
            }
            if(board[n-1][i] == 'O'){
                q.push({n-1,i});
            }
        }
        int drow[]= {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second; 
            visited[row][col] = 1;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !visited[nrow][ncol]){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
    //tc->0(N*M)
    //sc->0(N*M)
};