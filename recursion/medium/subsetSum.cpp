// Given an array nums of n integers. Return array of sum of all subsets of the array nums.
// Output can be returned in any order.
// Examples:
// Input : nums = [2, 3]
// Output : [0, 2, 3, 5]

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void generateSum(int ind,int currSum,vector<int>&result,vector<int>&nums){
      if(ind >= nums.size()){
        result.push_back(currSum);
        return;
      }
      currSum += nums[ind];
      generateSum(ind+1,currSum,result,nums);
      currSum -= nums[ind];
      generateSum(ind+1,currSum,result,nums);
      return;
    }
    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        vector<int>result;
        generateSum(0,0,result,nums);
        sort(result.begin(),result.end());
        return result;
    }
    // tc -> 0(2pown + 2pown* log(2pown));
    // sc -> 0(2pown)
    

};