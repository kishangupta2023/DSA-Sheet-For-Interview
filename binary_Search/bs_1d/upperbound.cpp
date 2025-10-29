// Upper Bound -> smallest index such that arr[ind] > target
#include<bits/stdc++.h>
using namespace std;
// for upper bound 
// ub = upper_bound(arr.begin(),arr.end(),x);
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int low = 0;
        int high = arr.size()-1;
        int res =  arr.size();
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] > target){
                res = mid;
                high= mid-1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};
