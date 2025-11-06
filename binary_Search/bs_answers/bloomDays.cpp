// minimum Number of Days to MAke m Bouquests 
// You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
// Example 1:
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
// Example 2:
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
// Output: -1
// Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMake(vector<int>&bloomDay,int d,int m,int k){
        int bouquest =0;
        int consecutive = 0;
        for(int x : bloomDay){
            if(x <= d){
                consecutive++;
                if(consecutive == k){
                    bouquest++;
                    consecutive =0;
                    if(bouquest == m) return true;
                }
            }else{
                consecutive =0;
            }
        }
        return bouquest >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = (int)bloomDay.size();
        if((long long)m*k > n) return -1;
        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int h = *max_element(bloomDay.begin(),bloomDay.end());
        for(int i=l;i<=h;i++){
            if(canMake(bloomDay,i,m,k)) return i;
        }
        return -1;
    }
    // tc -> 0((max-min)*N)

    // optimise way 
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = (int)bloomDay.size();
        if ((long long)m * k > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        // Binary search for smallest day such that canMake(day) is true
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay, mid, m, k)) {
                high = mid;       // possible — try earlier days
            } else {
                low = mid + 1;    // not possible — need to wait longer
            }
        }

        return low; // low == high and is the minimum day
    }

    // another way of finding is days possible
    int possible(vector<int>bloomDay,int day,int m ,int k){
        int cnt =0;
        int nofB =0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                cnt++;
            }else{
                nofB += (cnt/k);
                cnt =0;
            }
        }
        nofB +=(cnt/k);
        if(nofB >= m) return true;
        return false;
    }
};