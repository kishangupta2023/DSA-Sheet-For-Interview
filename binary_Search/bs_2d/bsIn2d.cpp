// search element in 2D
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool binarySearch(vector<vector<int>>&matrix,int target){
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = m*n-1;
        while(low <= high){
            int mid = (low+high)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col] == target){
                return true;
            }
            if(matrix[row][col] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = binarySearch(matrix,target);
        return ans;
    }
};