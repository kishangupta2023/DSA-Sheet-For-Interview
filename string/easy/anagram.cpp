// // Check Anagram whether string1 letter contains string 2 letters 
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"
// Output: false

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i=0;i<s.size();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(auto it:m1){
            if(it.second != m2[it.first]){
                return false;
            }
        }
        return true;
    }
    // tc -> 0(N)
    // sc ->(2*k)

    // optimal solution
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) return false;
        }

        return true;
    }
//     Time: O(n) → same as before.

// Space: O(26) → constant space, instead of using unordered_map (which has hashing overhead).
};