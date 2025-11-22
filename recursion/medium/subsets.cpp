// Subsets 
// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.
// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void generate(int ind,vector<int>&nums,vector<int>&res,vector<vector<int>>&ans){
        if(ind >= nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[ind]);
        generate(ind+1,nums,res,ans);
        res.pop_back();
        generate(ind+1,nums,res,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>res;
        generate(0,nums,res,ans);
        return ans;
    }
    // tc -> 0(2pown *n)
    // sc -> 0(2pown) outer space and for recursive call 0(n)
};