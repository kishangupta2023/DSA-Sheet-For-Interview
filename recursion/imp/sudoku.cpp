// 37. Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(int row,int col,vector<vector<char>>& board,char dig){
        for(int i=0;i<board.size();i++){
            if(board[row][i] == dig) return false;
            if(board[i][col] == dig) return false;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[3*(row/3)+i][3*(col/3)+j] == dig) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n =board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '.'){
                    for(char dig = '1';dig<='9';dig++){
                        if(possible(i,j,board,dig)){
                            board[i][j] = dig;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                 return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    // tc -> worst case 0(9pow(81))
    // sc -> 0(81)+0(1) = 0(1)
};