// Longest Consecutive Sequence 
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool linear(vector<int>&arr,int n){
        for(int i=0;i<arr.size();i++){
            if(arr[i] == n) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        int maxi =0;
        for(int i=0;i<n;i++){
            int x =nums[i];
            int cnt = 1;
            while(linear(nums,x+1) == true){
                x = x+1;
                cnt = cnt+1;
            }
            maxi =max(maxi,cnt);
        }
        return maxi;
    }
    // tc -> 0(N*N)
    // sc -> 0(1)


    // better solution 
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxi =1;
        int len = 1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]+1 == nums[i+1]){
                len++;
                maxi = max(maxi,len);
            }
            else if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                len = 1;
            }
        }
        return maxi;
    }

    int longestConsecutive(vector<int>& nums) {
        int n =  nums.size();
        if(n ==0) return 0;
        int longest =1;
        int cnt = 0;
        int lastsmaller = INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i] -1 == lastsmaller){
                cnt++;
                lastsmaller = nums[i];
            }else if(nums[i] != lastsmaller){
                cnt = 1;
                lastsmaller = nums[i];
            }
            longest = max(longest,cnt);
        }
    }
    // tc -> 0(NlogN)

    // optimal solution 
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int>s;
        s.insert(nums.begin(),nums.end());
        int maxi =1;
        for(auto it : s){
            if(s.find(it-1) == s.end()){
                int cnt = 1;
                int current = it;
                while(s.find(current+1) != s.end()){
                    cnt++;
                    current++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
    //  tc -> 0(N)
//    sc ->0(N)




};