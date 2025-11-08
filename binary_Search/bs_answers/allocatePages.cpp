// Allocate Minimum Pages 
// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int fun(vector<int>arr,int pages){
        int total =1;
        int noPages = 0;
        for(int i=0;i<arr.size();i++){
            if(noPages+arr[i] <= pages){
                noPages+=arr[i];
            }else{
                total++;
                noPages = arr[i];
            }
        }
        return total;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k) return -1;
        int maxi= *max_element(arr.begin(),arr.end());
        int totalSum = accumulate(arr.begin(),arr.end(),0);
        for(int i=maxi;i<=totalSum;i++){
            int cntStu = fun(arr,i);
            if(cntStu == k) return i;
        }
        return -1;
    }
    // tc -> 0(Sum-maxi+1)*n

    // optimal Solution 
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k) return -1;
        int low= *max_element(arr.begin(),arr.end());
        int high= accumulate(arr.begin(),arr.end(),0);
        int ans =0;
        while(low <= high){
          int mid =(low+high)/2;
          if(fun(arr,mid) <= k){
            ans = mid;
            high = mid-1;
          }else{
            low = mid+1;
          }
        }
        return ans;
    }
};