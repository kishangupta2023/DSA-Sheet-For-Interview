#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>&nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target);
    }
};