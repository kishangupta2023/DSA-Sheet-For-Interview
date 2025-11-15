// // Count Number of Homogenous Substring
// Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

// A string is homogenous if all the characters of the string are the same.

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: s = "abbcccaa"
// Output: 13
// Explanation: The homogenous substrings are listed as below:
// "a"   appears 3 times.
// "aa"  appears 1 time.
// "b"   appears 2 times.
// "bb"  appears 1 time.
// "c"   appears 3 times.
// "cc"  appears 2 times.
// "ccc" appears 1 time.
// 3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    int countHomogenous(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int count =0;
            for(int j=i;j<n;j++){
                if(s[j] == s[i]){
                    count++;
                }else{
                    break;
                }
            }
            ans = (ans+count)%mod;
        }
        return ans%mod;
    }
    // tc-> 0(N*N)

     int countHomogenous(string s) {
        long long ans = 0;
        int n = s.size();
        int i = 0;

        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;          // j ends at first different index or n
            long long len = j - i;                      // length of the run
            long long add = (len * (len + 1) / 2) % mod; // number of homogeneous substrings in this run
            ans = (ans + add) % mod;
            i = j; // move to next run
        }

        return (int)ans;
    }
    // tc -> 0(N)
    // sc -0(1)
};