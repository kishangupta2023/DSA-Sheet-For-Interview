// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int ind,int sum,int k,int n,vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans){
        if(sum > n || ds.size() > k) return;
        if(ds.size() == k ){
            if(sum == n){
               ans.push_back(ds);
               return;
            }
            return;
        }
        if(ind >= nums.size()) return;
        ds.push_back(nums[ind]);
        generate(ind+1,sum+nums[ind],k,n,nums,ds,ans);
        ds.pop_back();
        generate(ind+1,sum,k,n,nums,ds,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1;i<=9;i++) nums.push_back(i);
        vector<vector<int>>ans;
        vector<int>ds;
        generate(0,0,k,n,nums,ds,ans);
        return ans;
    }
    // tc -> 0(2pow(9)) == 0(512) == constant for recursive call 
    // sc ->0(R.k)  if result size is R and eaxch combination size = k 


    // more optimal 
        void generate(int start,int k,int target,vector<int>&ds,vector<vector<int>>&ans){
        if(k == 0){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(target < 0) return;
        for(int i=start;i<=10-k;i++){
            if(i > target) break;
            ds.push_back(i);
            generate(i+1,k-1,target-i,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        generate(1,k,n,ds,ans);
        return ans;
    }
    // tc -> 0(C(9,k)*k)
    // sc-> O(k)

};