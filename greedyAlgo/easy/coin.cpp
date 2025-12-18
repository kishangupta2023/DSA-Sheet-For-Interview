#include <bits/stdc++.h>
using namespace std;

// Function to compute minimum coins required for value V
vector<int> minCoins(int V) {
    // Available coin denominations
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;

    // Vector to store the result
    vector<int> ans;

    // Iterate from largest to smallest denomination
    for (int i = n - 1; i >= 0; i--) {
        // Use as many coins[i] as possible
        while (V >= coins[i]) {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    // Return the list of coins used
    return ans;
}

int main() {
    // Total amount
    int V = 49;

    // Call function to get coin list
    vector<int> ans = minCoins(V);

    // Print result
    cout << "The minimum number of coins is " << ans.size() << endl;
    cout << "The coins are " << endl;
    for (int coin : ans) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}