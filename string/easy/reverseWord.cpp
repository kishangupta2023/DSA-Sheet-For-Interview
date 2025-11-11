//  Reverse Words in a String
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string ss ="";
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                ss += s[i];
            }
            if(s[i] == ' ' || i == s.size()-1){
                if(!ss.empty()){
                ans.push_back(ss);
                }
                ss = "";
            }
        }
        string res ="";
        for(int i=ans.size()-1;i>=0;i--){
            res += ans[i];
            if(i != 0){
               res += ' ';
            }
        }
        return res;
    }
    // tc -> 0(n) sc -> 0(N)

    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.size();
        int start =0;
        int end =0;
        while(start < n){
            while(start < n && s[start] == ' ') start++;
            if(start >= n) break;
            end = start;
            while(end < n && s[end] != ' ') end++;
            reverse(s.begin()+start,s.begin()+end);
            start = end;
        }
        int i=0,j=0;
        while(j < n){
            while(j < n && s[j] == ' ') j++;
            while(j<n && s[j] != ' ') s[i++] = s[j++];
            while(j < n && s[j] == ' ') j++;
            if(j < n) s[i++] =' ';
        }

        s.resize(i);
        return s;
    }
    // tc -> 0(N) sc-> 0(1)
};