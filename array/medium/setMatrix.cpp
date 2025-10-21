
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> arrIndex(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    arrIndex[i][j] = -1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arrIndex[i][j] == -1){
                    for(int k =0;k<m;k++){
                        matrix[i][k] = 0;
                    }
                    for(int k=0;k<n;k++){
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }

    // brute force approach 
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    for(int k=0;k<n;k++){
                        if(matrix[k][j] != 0){
                        matrix[k][j] = -1;
                        }
                    }
                    for(int k=0;k<m;k++){
                        if(matrix[i][k] != 0){
                            matrix[i][k] = -1;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
     // tc - 0(N*M)*0(N+m)*2

    // better apporach
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col[m] = {0};
        int row[n] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();  
        int m = matrix[0].size(); 
        // int col[m] = {0}; - > matrix[0][....]
        // int row[n] = {0};   -> matrix[...][0]
        int col0 = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    // mark he ith row 
                    matrix[i][0] = 0;
                    // mark the jth col
                    if(j != 0) matrix[0][j] = 0;
                    else col0=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] != 0){
                    if(matrix[0][j] == 0 || matrix[i][0] == 0){
                         matrix[i][j] = 0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++) matrix[0][j] = 0;
        }
        if(col0 == 0){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }
        
    }
    
};