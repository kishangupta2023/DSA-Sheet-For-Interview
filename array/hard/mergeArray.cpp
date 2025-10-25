// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int l =0;
        int r =0;
        while(l<m && r < n){
            if(nums1[l] <= nums2[r]){
                ans.push_back(nums1[l]);
                l++;
            }else{
                ans.push_back(nums2[r]);
                r++;
            }
        }
        while(l < m){
            ans.push_back(nums1[l]);
            l++;
        }
        while(r < n){
            ans.push_back(nums2[r]);
            r++;
        }
        for(int i=0;i<ans.size();i++){
            if(i < m){
                nums1[i] = ans[i];
            }else{
                nums2[i-m] = ans[i];
            }
        }
    }
    // tc -> 0(2(N+M))
    // sc -> 0(N+M)

    // better solution 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m;
        int r =0;
        while(l >=0 && r < n){
            if(nums1[l] > nums2[r]){
                swap(nums1[l],nums2[r]);
                l--;
                r++;
            }else{
                break;
            }
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        for(int i=m;i<m+n;i++){
            nums1[i] = nums2[i-m];
        }
    }
    // tc->0(min(n,m))+0(nlogn)+0(mlogm)
    // sc->0(1)


    // more optimal solution
    
    void swapIfGreater(vector<int>&nums1,vector<int>&nums2,int ind1,int ind2){
        if(nums1[ind1] > nums2[ind2]){
            swap(nums1[ind1],nums2[ind2]);
        }
    }
    void merge(vector<int>&nums1,int m,vector<int>&nums2,int n){
        int len = m+n;
        int gap = (len/2)+(len%2);
        while(gap > 0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                if(left < m && right >=m){
                    swapIfGreater(nums1,nums2,left,right-m);
                }
                else if(left >= m){
                    swapIfGreater(nums2,nums2,left-m,right-m);
                }
                // arr1 and arr1
                else {
                    swapIfGreater(nums1,nums1,left,right);
                }
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = (gap/2) + (gap%2);
        }
    }
    // tc -> 0(log2(n+m)) +0(N+m)
    // sc -> 0(1)
};

