// Koko eating bananas 
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.
// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long computeTime(vector<int>&piles,int k){
        long long ans = 0;
        for(int i=0;i<piles.size();i++){
            ans += ceil((double)piles[i]/k);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h){
        int ans =0;
        int m = *max_element(piles.begin(),piles.end());
        for(int i=1;i<=m;i++){
            long long req = computeTime(piles,i);
            if(req <= h){
                ans = i;
                break;
            }
        }
        return ans;   
    }
    // tc -> 0(maxArray element*n)

    // optimise way 
    int minEatingSpeed(vector<int>& piles, int h){
        int ans =0;
        int low =1;
        int high= *max_element(piles.begin(),piles.end());
        while(low <= high){
            int mid = (low+high)/2;
            long long x =computeTime(piles,mid);
            if(x <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;   
    }
};