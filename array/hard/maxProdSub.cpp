// Maximum Product Subarray - 
// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
// Note that the product of an array with a single element is the value of that element
// Example 1:
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   // bruteforce Approach 
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            int res = 1;
            for(int j=i;j<n;j++){
                res *= nums[j];
                maxi = max(res,maxi);
            }
        }
        return maxi;
    }

    // optimal Solution 
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int pre = 1;
        int suff = 1;
        for(int i=0;i<n;i++){
            if(pre ==0) pre = 1;
            if(suff == 0) suff =1;
            pre = pre * nums[i];
            suff = suff*nums[n-i-1];
            ans = max(ans,max(pre,suff));
        }
        return ans;
    }

};