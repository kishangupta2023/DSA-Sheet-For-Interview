// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool palindrome(string s,int start,int end){
        while(s[start++] != s[end]--){
            return false;
        }
        return true;
    }
    void generate(int ind,vector<string>&paths,vector<vector<string>>&ans,string &s){
        if(ind == s.size()){
            ans.push_back(paths);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(palindrome(s,ind,i)){
                paths.push_back(s.substr(ind,i-ind+1));
                generate(i+1,paths,ans,s);
                paths.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>paths;
        generate(0,paths,ans,s);
        return ans;
    }
};
 