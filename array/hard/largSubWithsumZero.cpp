// Largest Subarray with Zero Sum | Amazon 

#include<bits/stdc++.h>
using namespace std;
class Solution{
    int maxLength(vector<int>&nums){
        int n = nums.size();
        unordered_map<int,int>mpp;
        int maxi = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum == 0){
                maxi = i+1;
            }
            else{
                if(mpp.find(sum) != mpp.end()){
                    maxi = max(maxi,i-mpp[sum]);
                }else{
                    mpp[sum] = i;
                }
            }
        }
        return maxi;
    }
    // tc -> 0(N*log(N))
    // sc -> 0(N)
};