// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.
// Example 1
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // bruteforce apporach 
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] + nums[j] +nums[k] == 0){
                        vector<int>triplet = {nums[i],nums[j],nums[k]};
                        sort(triplet.begin(),triplet.end());
                        ans.push_back(triplet);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] + nums[j] +nums[k] == 0){
                        vector<int>triplet = {nums[i],nums[j],nums[k]};
                        sort(triplet.begin(),triplet.end());
                        ans.insert(triplet);
                    }
                }
            }
        }
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
    // tc -> 0(N*N*N*log(n));
    // sc -> 0(2*no of triplets)

    // better solution using hashing 
    vector<vector<int>>threeSum(vector<int>&nums){
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            set<int>hashset;
            for(int j=i+1;j<n;j++){
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int>temp = {nums[i],third,nums[j]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[i]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
    // tc -> 0(N*N*log(size of set));
    // sc -> 0(N)+0(no of unique triplet)*2; 


    // optimal approach 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // skip duplicate left
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // skip duplicate right
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
        }
        return ans;
    }
    // tc -> 0(n*N)
    // sc ->0(1)

};