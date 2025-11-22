// Generate parentheses 
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:
// Input: n = 1
// Output: ["()"]

#include<bits/stdc++.h>
using namespace std;

class Solution{
    void generate(int open,int close,int n ,string & par,vector<string>&ans){
        if(par.size() == n){
            ans.push_back(par);
            return;
        }
        if(open < n){
            par.push_back('(');
            generate(open+1,close,n,par,ans);
            par.pop_back();
        }
        if(close < open){
            par.push_back(')');
            generate(open,close+1,n,par,ans);
            par.pop_back();
        }
    }
    vector<string>generateParenthesis(int n){
        vector<string>ans;
        string par;
        generate(0,0,n,par,ans);
        return ans;
    }
    // tc -> 0(Cn * N);
    // tc=== 0(4pow(n) * root(n));
    // sc -> 0(n) recursion depth output storage 0(Cn*n)
};