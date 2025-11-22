// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
// Example 1:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int ind,int sum,int target,vector<int>& candidates,vector<int>&lists,vector<vector<int>>&ans){
        if(sum == target){
            ans.push_back(lists);
            return;
        }
        if(sum > target || ind >= candidates.size()) return;

        lists.push_back(candidates[ind]);
        generate(ind,sum+candidates[ind],target,candidates,lists,ans);
        lists.pop_back();
        generate(ind+1,sum,target,candidates,lists,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>lists;
        generate(0,0,target,candidates,lists,ans);
        return ans;
    }
    // tc - > 0(2pown * k)
};