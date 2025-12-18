// // Fractional knapSack 
// Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places.

// Examples :

// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<double,int>>items;
        for(int i=0;i<n;i++){
            double r = double(val[i])/wt[i];
            items.push_back({r,i});
        }
        sort(items.begin(),items.end(),[](auto &a,auto &b){
            return a.first > b.first;
        });
        double ans =0.0;

        for(auto it : items){
            if(capacity == 0) break;
            int idx = it.second;
            int w = wt[idx];
            int value = val[idx];
            if(w <= capacity){
                ans += value;
                capacity -= w;
            }
            else{
                ans += capacity*it.first;
                capacity = 0;
                break;
            }
        }
        return ans;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<double,int>>items;
        for(int i=0;i<n;i++){
            double r = double(val[i])/wt[i];
            items.push_back({r,wt[i]});
        }
        sort(items.begin(),items.end(),[](auto &a,auto &b){
            return a.first > b.first;
        });
        double ans =0.0;

        for(auto it : items){
            if(capacity == 0) break;
            int w = it.second;
            double value = it.first*it.second;
            if(w <= capacity){
                ans += value;
                capacity -= w;
            }
            else{
                ans += capacity*it.first;
                capacity = 0;
                break;
            }
        }
        return ans;
    }

    // tc O(n) + O(n log n) + O(n) = O(n log n)
    // sc -> 0(n) + 0(1)

};






