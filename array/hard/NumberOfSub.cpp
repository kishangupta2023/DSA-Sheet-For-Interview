// Number of Subarrays with xor K | Brute - Better - Optimal
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  // bruteforce Approach 
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        long ans=0;
        for(int i=0;i<n;i++){
            int x =0;
            for(int j=i;j<n;j++){
                x = x^arr[j];
                if(x == k){
                    ans++;
                }
            }
        }
        return ans;
    }
    // tc -> 0(N*N)

    // optimal solution
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int>mpp;
        mpp[0] =1;
        int count = 0;
        int xr =0;
        for(int i=0;i<n;i++){
            xr = xr^arr[i];
            int need = xr^k;
            count += mpp[need];
            mpp[xr]++;
        }
        return count;
    }
    //tc -> 0(N*logN) || 0(N)
    // sc -> 0(N)
};