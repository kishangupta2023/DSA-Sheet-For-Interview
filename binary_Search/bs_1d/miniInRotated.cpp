// MInimum in Rotated Sorted Array {unique}
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.
// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>&nums){
        int low =0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[low] <= nums[mid]){
                ans =min(ans,nums[low]);
                low = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
    // optimise binary search 
    int binarySearch(vector<int>&nums){
        int low =0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[low] <= nums[high]){
                ans = min(ans,nums[low]);
                break;
            }
            if(nums[low] <= nums[mid]){
                ans =min(ans,nums[low]);
                low = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
    int findMin(vector<int>& nums) {
        return binarySearch(nums);
    }
};