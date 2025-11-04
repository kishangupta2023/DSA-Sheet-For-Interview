// Search in a rotated Sorted Array 
// Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.
// Examples:
// Input : nums = [4, 5, 6, 7, 0, 1, 2], k = 0
// Output: 4
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>&nums,int target){
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int k) {
       return binarySearch(nums,k);
    }
};

int main(){
    vector<int>nums = {4,5,6,7,0,1,2};
    int k = 0;
    Solution obj;
    int ans = obj.search(nums,k);
    cout<<ans<<endl;
    return 0;
}