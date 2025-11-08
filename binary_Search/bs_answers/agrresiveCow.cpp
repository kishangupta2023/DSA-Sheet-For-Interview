// Aggresive Cows 
// You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples:

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows in this case is 3, which is the largest among all possible ways.
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPossible(vector<int>&stalls,int d,int k){
        int n = stalls.size();
        int store = stalls[0];
        int count =1;
        for(int i=1;i<n;i++){
            if(stalls[i] - store >= d){
                count++;
                store = stalls[i];
                if(count == k) return true;
            }
        }
        return false;
    }
    // bruteforce approach 
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int maxi = stalls[n-1];
        int ans = 0;
        for(int i=1;i<=maxi;i++){
            if(isPossible(stalls,i,k)){
                ans = i;
            }else{
                break;
            }
        }
        return ans;
    }
    // tc->0(N*N)

    // optimise approach 
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int maxi = stalls[n-1];
        int ans = 0;
        for(int i=1;i<=maxi;i++){
            if(isPossible(stalls,i,k)){
                ans = i;
            }else{
                break;
            }
        }
        return ans;
    }
    // 0(logN*N)+0(nlogn)
};