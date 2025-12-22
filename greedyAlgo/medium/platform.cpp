// Minimum number of platforms required for a railway
// Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

// Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900).

// Examples:

// Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
// Output: 3
// Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
// Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
// Output: 1
// Explanation: All train times are mutually exclusive. So we need only one platform.
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int maxCount =0;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            int count = 0;
            int time = arr[i];
            for(int j=0;j<n;j++){
                    if(arr[j] <= time && dep[j] >= time){
                       count++;
                    }
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
    // tc -> 0(n*n)
    // sc -> 0(1)

     int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n = arr.size();
        int i=0;
        int j =0;
        int cnt =0;
        int maxCnt = 0;
        while(i < n ){
            if(arr[i] <= dep[j]){
                cnt++;
                maxCnt = max(maxCnt,cnt);
                i++;
            }else{
                cnt--;
                j++;
            }
        }
        return maxCnt;
    }
    // tc -> 0(2n*logn)== 0(2*(nlogn + n))
    //sc -> 0(1)
};
