// Kth missing Positive Number 
// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.
// Example 1:
// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // bruteforce Approach 
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i] <= k) k++;
            else break;
        }
        return k;
    }
    //tc -> 0(N)
    //sc -> 0(1)


    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());
        vector<int>res;
        int x =0;
        int i=1;
        while(k){
            if(st.find(i) == st.end()){
                res.push_back(i);
                k--;
            }
            i++;
        }
        return res.back();
    }

    // optimsed way binary search
    int findKthPositive(vector<int>& arr, int k) {
        int low =0;
        int high = arr.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            int x = arr[mid] - (mid+1);
            if(x < k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        // int more =k-(arr[high]-(high+1));
        // ans = arr[high] + more;// k+high+1 = (k +low)
        return (low+k);
    }
       

};