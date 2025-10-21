// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top =0;
        int buttom = n-1;
        int left = 0;
        int right =m-1;
        

        while(top <=buttom && left <=right){
            for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
            }
           top++;
        for(int i=top;i<=buttom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= buttom){
        for(int i=right;i>=left;i--){
            ans.push_back(matrix[buttom][i]);
        }
        buttom--;
        }
        if(left <=right){
        for(int i=buttom;i>=top;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        }
    }
    return ans; 
    }
};