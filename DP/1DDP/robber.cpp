// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// Example 1:
// Input: nums = [1,2,3,1]
// Output: 4

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rec(int n ,vector<int>&nums,vector<int>&dp){
        if(n < 0) return 0;
        if(n == 0) return nums[0];
        if(dp[n] != -1) return dp[n];
        int take = nums[n] + rec(n-2,nums,dp);
        int nottake = rec(n-1,nums,dp);
        return dp[n] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int cost = rec(n-1,nums,dp);
        return cost;
    }
};