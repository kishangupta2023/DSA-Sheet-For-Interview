// Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.
// Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 
// Examples :
// Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
// Output: 3
// Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.


// lowerbound -> smallest index such that arr[ind] >= target

// lb = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
//example lb = lower_bound(arr+2,arr+7) this will search in [2,6]

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int lowerBound(vector<int>&arr,int target){
        int low = 0;
        int n = arr.size();
        int high = arr.size()-1;
        int ans = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    
};
