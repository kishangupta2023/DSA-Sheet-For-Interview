// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int count =0;
        int currEnd = 0;
        int currFarthest = 0;
        for(int i=0;i<n-1;i++){
            currFarthest = max(currFarthest,i+nums[i]);
            if(i == currEnd){
                count++;
                currEnd = currFarthest;
            }
        }
        return count;
    }
};
// tc -> 0(n)
// sc ->0(1)