// Find the peak Element in a 2d Matrix
// Given a 2D matrix mat[][], identify any peak element within the matrix.

// An element is considered a peak if it is greater than or equal to its four immediate neighbors: top, bottom, left, and right. For corner and edge elements, any missing neighbors are treated as having a value of negative infinity.

// Note: A peak element is not necessarily the global maximum, it only needs to satisfy the condition relative to its adjacent elements. Multiple peak elements may exist, return any one of them.
// Note that the driver code will print true if you return the correct position of peak element, else it will print false.

// Examples:

// Input: mat[][] = [[10, 20, 15],           
//                 [21, 30, 14],
//                  [7, 16, 32]]
// Output: true

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        vector<int>ans;
        int n= mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i == 0 || mat[i-1][j] <= mat[i][j]) && (i == n-1 || mat[i+1][j] <= mat[i][j]) && (j==0 || mat[i][j-1] <= mat[i][j]) && (j == m-1 || mat[i][j+1] <= mat[i][j])){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return {-1,-1};
    }

    int findMaxIndex(vector<vector<int>>&mat,int n,int col){
        int maxValue = INT_MIN;
        int index = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > maxValue){
            maxValue = mat[i][col];
            index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = (low+high)/2;
            int maxRowIndex = findMaxIndex(mat,n,mid);
            int left = mid-1 >=0 ? mat[maxRowIndex][mid-1] : INT_MIN;
            int right = mid+1 < m ? mat[maxRowIndex][mid+1]:INT_MIN;
            if(mat[maxRowIndex][mid] >= left && mat[maxRowIndex][mid] >= right){
                return {maxRowIndex,mid};
            }
            else if(mat[maxRowIndex][mid] < left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
    // tc-> 0(N*logM);
    // sc -> 0(1);
};


