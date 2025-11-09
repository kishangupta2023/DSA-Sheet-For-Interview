//  Row With Maximum Ones
// Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.

// In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.

// Return an array containing the index of the row, and the number of ones in it.
// Example 1:
// Input: mat = [[0,1],[1,0]]
// Output: [0,1]
// Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the answer is [0,1].
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// bruteforce Approach 
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans(2);
        int res =0;
        for(int i=0;i<mat.size();i++){
            int count = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            if(count > res){
                ans[0] = i;
                ans[1] = count;
                res = count;
            }
        }
        return ans;
    }
    // tc->0(N*N)
    // sc 0(2)

};
//when row is sorted 

class Solution {
  public:
    int lowerBound(vector<int>&arr,int target){
        int low = 0;
        int high = arr.size()-1;
        int ans = arr.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &mat) {
        // code here
        int count_max = -1;
        int index = -1;
        int m = mat[0].size();
        for(int i=0;i<mat.size();i++){
            int cnt =m-lowerBound(mat[i],1);
            if(cnt > count_max){
                count_max = cnt;
                index =i;
            }
            
        }
        return index;
    }
    // tc->0(N*logM)
    
};