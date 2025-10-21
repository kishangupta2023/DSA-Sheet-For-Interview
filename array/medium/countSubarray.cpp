// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mpp;
        mpp[0] = 1;
        int preSum = 0;
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            int remove = preSum - k;
            cnt+=mpp[remove];
            mpp[preSum] += 1;
        }
        return cnt;
    }
    // tc -> 0(N*logN)
};