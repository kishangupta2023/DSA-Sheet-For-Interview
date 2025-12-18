// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

// Example 1:

// Input: s = "()"
// Output: true
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool stringCheck(string &s,int ind, int cnt){
        if(cnt < 0) return false;
        if(ind == s.size()){
            return (cnt==0);
        }
        if(s[ind] == '('){
            return stringCheck(s,ind+1,cnt+1);
        }
        if(s[ind] == ')'){
            return stringCheck(s,ind+1,cnt-1);
        }
        return stringCheck(s,ind+1,cnt+1) || stringCheck(s,ind+1,cnt-1) || stringCheck(s,ind+1,cnt);
    }
    bool checkValidString(string s) {
        return stringCheck(s,0,0);
    }
    // tc -> 3pown
    // sc -> 0(N)

    bool checkValidString(string s){
        int min  =0;
        int max= 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                min++;
                max++;
            }
            else if(s[i] == ')'){
                min--;
                max--;
            }else{
                min--;
                max++;
            }
            if(min < 0) min = 0;
            if(max<0) return false;
        }
        return (min ==0);
    }
};