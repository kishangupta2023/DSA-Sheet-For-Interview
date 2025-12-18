// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

// Note that you do not have any change in hand at first.

// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int count5 = 0;
        int count10 = 0;
        if(bills[0] != 5) return false;
        int toGive = 0;
        for(int i=0;i<n;i++){
            toGive = bills[i] - 5;
            if(bills[i] == 5) count5++;
            else if(bills[i] == 10) count10++;

            if(toGive == 0){
                continue;
            }
            else if(toGive == 5 && count5 != 0){
                count5--;
            }
            else if(toGive == 10 && count10 != 0){
                count10--;
            }else if(toGive == 10 && count10 == 0 && count5 >=2){
                count5 -= 2;
            }else if(toGive == 15 && count10 != 0 && count5 != 0){
                count10--;
                count5--;
            }else if(toGive == 15 && count5 >=3){
                count5 -=3;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int count5 = 0;
        int count10 = 0;
        for(int i=0;i<n;i++){
            if(bills[i] == 5) count5++;
            else if(bills[i] == 10){
                if(count5){
                    count5--;
                }else{
                    return false;
                }
            }else{
                if(count10 && count5){
                    count10--;
                    count5--;
                }
                else if(count5 >= 3){
                    count5 -=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};