// Given an array of integers arr[]. You have to find the Inversion Count of the array. 
// Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].
// Examples:
// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i < j && arr[i] > arr[j]){
                    count++;
                }
            }
        }
        return count;
    }

    int count =0;
    void merge(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }// right is smaller 
            else{
                temp.push_back(arr[right]);
                count += (mid-left+1);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }

    void mergeSort(vector<int>&arr,int low,int high){
        if(low >= high) return;
        int mid = low + (high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }

    int inversionCount(vector<int> &arr) {
        // Code Here
        int n =arr.size();
        mergeSort(arr,0,n-1);
        return count;
    }


    // Another way of previous Solution 
    int merged(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int left = low;
        int right = mid+1;
        int count = 0;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }// right is smaller 
            else{
                temp.push_back(arr[right]);
                count += (mid-left+1);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
        return count;
    }

    int mergeSorts(vector<int>&arr,int low,int high){
        int count =0;
        if(low >= high) return count;
        int mid = low + (high-low)/2;
        count += mergeSorts(arr,low,mid);
        count += mergeSorts(arr,mid+1,high);
        count += merged(arr,low,mid,high);
        return count;
    }

    int inversionCount(vector<int> &arr) {
        // Code Here
        int n =arr.size();
        int ans = mergeSorts(arr,0,n-1);
        return ans;
    }
    // tc -> 0(nlogn)
    //sc -> 0(N)

};