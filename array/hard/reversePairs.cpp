// Reverse Pair 
// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
// Example 1:
// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// bruteForce Approach 
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] > 2*nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
    //tc ->  0(N*N)
    // sc -> 0(1)

    // optimal Solution
    int count =0;
    void merge(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int left = low;
        int right = mid+1;
        int count = 0;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<= high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
    void countPairs(vector<int>&arr,int low,int mid,int high){
        int right = mid+1;
        for(int i=low;i<=mid;i++){
            while(right <= high && arr[i] > 2ll*arr[right]){
                right++;
            }
            count += (right-(mid+1));
        }
    }
  
    void mergeSort(vector<int>&arr,int low,int high){
        if(low >= high) return;
        int mid = low + (high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        countPairs(arr,low,mid,high);
        merge(arr,low,mid,high);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return count;
    }

    // now optimsing and reomving the global variable 
    void merged(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int left = low;
        int right = mid+1;
        int count = 0;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<= high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
    int countPair(vector<int>&arr,int low,int mid,int high){
        int right = mid+1;
        int count =0;
        for(int i=low;i<=mid;i++){
            while(right <= high && arr[i] > 2ll*arr[right]){
                right++;
            }
            count += (right-(mid+1));
        }
        return count;
    }
  
    int mergeSorts(vector<int>&arr,int low,int high){
        int cnt =0;
        if(low >= high) return cnt;
        int mid = low + (high-low)/2;
        cnt += mergeSorts(arr,low,mid);
        cnt += mergeSorts(arr,mid+1,high);
        cnt += countPair(arr,low,mid,high);
        merged(arr,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSorts(nums,0,n-1);  
    }

    // tc -> logn*(n+n) == 2n*logn
    // sc -> 0(N)
    // distorting the array explain itv to interviewer 
    
};