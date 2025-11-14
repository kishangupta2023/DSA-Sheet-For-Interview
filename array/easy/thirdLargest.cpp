// Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

// Example 1:

// Input: nums = [3,2,1]
// Output: 1
// Explanation:
// The first distinct maximum is 3.
// The second distinct maximum is 2.
// The third distinct maximum is 1.
// Example 2:

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>()); // descending
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); // remove duplicates
        if (nums.size() < 3) return nums[0]; // max
        return nums[2]; // third distinct maximum
    }
    // tc -> 0(nlogn)
    // sc -> 0(1)
     
    int thirdMax(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end()); // unique + sorted ascending

        if (st.size() < 3) return *st.rbegin(); // largest when < 3 distinct
        auto it = st.rbegin(); // largest
        ++it; // second largest
        ++it; // third largest
        return *it;
    }
    // or 
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = -1;
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        if(st.size() < 3) return *st.rbegin();
        else{
            st.erase(prev(st.end()));
            st.erase(prev(st.end()));
            ans = *st.rbegin();
        }
        return ans;
    }
    // tc -> 0(nlogn)
    // sc -> 0(n)

    int thirdMax(vector<int>& nums) {
        // Use long long sentinel smaller than any int
        long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
        for (int x : nums) {
            // skip duplicates of tracked values
            if (x == first || x == second || x == third) continue;

            if (x > first) {
                // shift down
                third = second;
                second = first;
                first = x;
            } else if (x > second) {
                third = second;
                second = x;
            } else if (x > third) {
                third = x;
            }
        }

        // If third wasn't set, return the maximum (first)
        if (third == LLONG_MIN) return (int)first;
        return (int)third;
    }
    // 0(n)

};