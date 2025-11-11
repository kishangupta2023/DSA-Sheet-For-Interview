// Isomorphic Strings 
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// Example 1:
// Input: s = "egg", t = "add"
// Output: true
// Explanation:
// The strings s and t can be made identical by:
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char>m1;
        unordered_map<char,char>m2;
        for(int i=0;i<s.size();i++){
            char c1 = s[i] , c2 = t[i];
            if(m1.count(c1) && m1[c1] != c2) return false;
            if(m2.count(c2) && m2[c2] != c1) return false;
            m1[c1] = c2;
            m2[c2] = c1;
        }
        return true;
    }
    // tc -> 0(n) in worst case 0(N*N)

    //If chars are only lowercase letters ('a'..'z')
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int m1[26], m2[26];
        for (int i = 0; i < 26; ++i) m1[i] = m2[i] = -1;

        for (int i = 0; i < (int)s.size(); ++i) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            if (m1[a] == -1 && m2[b] == -1) {
                m1[a] = b; m2[b] = a;
            } else if (m1[a] != b || m2[b] != a) return false;
        }
        return true;
    }

    //Last-seen index trick (single arrays)
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int lastS[256] = {0}, lastT[256] = {0};

        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char c1 = s[i], c2 = t[i];
            if (lastS[c1] != lastT[c2]) return false;
            lastS[c1] = lastT[c2] = i + 1; // store i+1 so default 0 means "never seen"
        }
        return true;
    }
};
