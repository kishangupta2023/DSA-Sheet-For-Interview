// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.
// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // bruteforce approach 
    vector<vector<int>>fourSum(vector<int>& nums,int target){
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l = k+1;l<n;l++){
                        long long sum = nums[i] +nums[j];
                        sum += nums[k];
                        sum +=nums[l];
                        if(sum == target){
                            vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
    // tc -> 0(N*N*N*N)
    // sc -> 0(no of fours)*2

    // better approach 
    vector<vector<int>>fourSum(vector<int>& nums,int target){
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long> hashset;
                for(int k=j+1;k<n;k++){
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int>temp ={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
    // tc -> 0(N*N*N*log(no of element in set))
    // sc -> 0(N) + 0(no of fours)*2

   // optimesed solution 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            for(int j=i+1;j<n;j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
                int left = j+1;
                int right = n-1;
                while(left < right){
                    long long sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum == target){
                        vector<int>temp = {nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(temp);
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if(sum < target){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return ans;
    }
    // tc -> 0(N*N*N)
};