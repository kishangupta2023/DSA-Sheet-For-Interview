// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int ind,vector<int>&nums,vector<int>&lists,vector<vector<int>>&ans){
        ans.push_back(lists);  
        for(int i=ind;i<nums.size();i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            lists.push_back(nums[i]);
            generate(i+1,nums,lists,ans);
            lists.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>lists;
        generate(0,nums,lists,ans);
        return ans;
    }
};