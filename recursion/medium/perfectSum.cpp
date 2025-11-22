// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

// Examples:

// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int res(int ind,int sum ,vector<int>& arr, int target){
        if(ind >= arr.size()){
        if(sum == target){
            return 1;
        }
            return 0;
        }
        sum += arr[ind];
        int left =res(ind+1,sum,arr,target);
        sum -= arr[ind];
        int right = res(ind+1,sum,arr,target);
        return left+right;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        return res(0,0,arr,target);
    }
};