// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 // brutefoce solution 
 void generate(int ind,int sum,int target,vector<int>& candidates,vector<int>&lists,set<vector<int>>&ans){
        if(sum == target){
            ans.insert(lists);
            return;
        }
        if(sum > target || ind >= candidates.size()) return;

        lists.push_back(candidates[ind]);
        generate(ind+1,sum+candidates[ind],target,candidates,lists,ans);
        lists.pop_back();
        generate(ind+1,sum,target,candidates,lists,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        vector<int>lists;
        generate(0,0,target,candidates,lists,ans);
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
    // tc -> 0(2pown * klog(set size))

// better solution 

    void generate(int ind,int target,vector<int>& candidates,vector<int>&lists,vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(lists);
            return;
        }
        
        for(int i=ind;i<candidates.size();i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            lists.push_back(candidates[i]);
            generate(i+1,target-candidates[i],candidates,lists,ans);
            lists.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>lists;
        generate(0,target,candidates,lists,ans);
        return ans;
    }
    
};