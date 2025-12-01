// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool dfs(int i,int j,int idx,vector<vector<char>>& board, string &word){
        if(idx == word.size()) return true;
        int n = board.size();
        int m = board[0].size();
        if(i < 0 || j < 0 || i >= n || j >=m || board[i][j] != word[idx]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#'; // for visited 
        bool found = dfs(i+1,j,idx+1,board,word) ||dfs(i-1,j,idx+1,board,word) || dfs(i,j+1,idx+1,board,word) || dfs(i,j-1,idx+1,board,word);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};