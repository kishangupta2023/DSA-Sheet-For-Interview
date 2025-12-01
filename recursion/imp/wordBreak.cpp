// Word Break 
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> Dict(wordDict.begin(),wordDict.end());
        vector<bool>dp(n+1,false);
        int maxLen = 0;
        for(int i=0;i<wordDict.size();i++){
            maxLen = max(maxLen,(int)wordDict[i].size());
        }
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j = max(0,i-maxLen);j<i;j++){
                if(dp[j] && Dict.find(s.substr(j,i-j)) != Dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};