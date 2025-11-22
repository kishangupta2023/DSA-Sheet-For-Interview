// //Sort a Stack
// You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).

#include<bits/stdc++.h>
using namespace std;

class Solution{
    void sortedInserted(stack<int>&st,int x){
        if(st.empty() || st.top() < x){
            st.push(x);
            return;
        }
        int top = st.top();
        st.pop();
        sortedInserted(st,x);
        st.push(top);
    }
    void sortStack(stack<int>&st){
        if(st.empty()) return;
        int temp = st.top();
        st.pop();
        sortedInserted(st,temp);
    }

    // Reverse a stack 
    void buttomInsert(stack<int>&st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        buttomInsert(st,x);
        st.push(temp);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int temp = st.top();
        st.pop();
        reverseStack(st);
        buttomInsert(st,temp);
    }
};