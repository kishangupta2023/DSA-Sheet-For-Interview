// Median in a 2d MAtrix 
// Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.
// Examples:
// Input: mat[][] = [[1, 3, 5], 
//                 [2, 6, 9], 
//                 [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m = mat[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(mat[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        int res = ans[(n*m)/2];
        return res;
    }

    // optimal Solution
    int upperBound(vector<int>& arr, int target) {
        // code here
        int low = 0;
        int high = arr.size()-1;
        int res =  arr.size();
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] > target){
                res = mid;
                high= mid-1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
    int countSmallEqual(vector<vector<int>>&mat,int n,int m ,int x){
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += upperBound(mat[i],x);
        }
        return cnt;
    } 
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i=0;i<n;i++){
            low = min(low,mat[i][0]);
            high = max(high,mat[i][m-1]);
        }
        int req = (n*m)/2;
        while(low <= high){
            int mid = (low+high)/2;
            int smallEqual= countSmallEqual(mat,n,m,mid);
            if(smallEqual <= req) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
    // tc -> 0(log(1e9)*N*logM)
};