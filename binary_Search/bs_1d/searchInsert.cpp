// Search Insert Position 
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// better approach 
//  just find the lower_bound 

// can be a solution 
    int binarySearch(vector<int>&nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    int searchInsert(vector<int>& nums, int target) {
        int ans = binarySearch(nums,target);
        if(ans != -1) return ans;
        int res = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return res;
    }
};