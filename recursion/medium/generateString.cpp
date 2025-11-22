// Generate binary Strings without Adjacent Zeros 
// You are given a positive integer n.
// A binary string x is valid if all substrings of x of length 2 contain at least one "1".
// Return all valid strings with length n, in any order.
// Example 1:
// Input: n = 3
// Output: ["010","011","101","110","111"]

#include<bits/stdc++.h>
using namespace std;

class Solution{
    void generate(int n,string &cur,vector<string>&ans){
        if((int)cur.size() == n){
            ans.push_back(cur);
            return;
        }
        // add only 1 
        cur.push_back('1');
        generate(n,cur,ans);
        cur.pop_back();

        // add only 0 
        if(cur.empty() || cur.back() == '1'){
            cur.push_back('0');
            generate(n,cur,ans);
            cur.pop_back();
        }
    }
    vector<string> validString(int n){
        vector<string>ans;
        string cur;
        generate(n,cur,ans);
        return ans;
    }
};