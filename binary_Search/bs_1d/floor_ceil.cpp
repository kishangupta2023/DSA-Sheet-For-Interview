// Floor and Ceil in sorted array 
// Floor-> largest no in array <= x 
// ceil -> smallest no in array >= x 

#include<bits/stdc++.h>
using namespace std;
class Solution{

    // floor 
    int floor(vector<int>&nums,int target){
        int ans = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid =(low+high)/2;
            if(nums[mid] <= mid){
                ans=nums[mid];
                low = mid +1;
            } else{
                high = mid-1;
            }
        }
        return ans;
    }

    // ceil = lower_bound
    
};