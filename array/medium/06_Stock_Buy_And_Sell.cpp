/*
💡 Problem: Stock Buy and Sell

🧠 Task:
Ek array diya gaya hai jisme prices[i] ith day pe stock ki price hai.
Ek din buy karo aur baad mein sell karo taaki maximum profit ho.
Agar profit possible nahi, toh 0 return karo.

🧪 Example:
Input: prices = [7, 1, 5, 3, 6, 4]
Output: 5 (Buy on day 2 (price = 1), sell on day 5 (price = 6), profit = 6 - 1 = 5)

Input: prices = [7, 6, 4, 3, 1]
Output: 0 (No profit possible)
*/

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Nested Loops)
// -------------------------------------------------
/*
📘 Steps:
1. Har possible buy day ke liye (i), har possible sell day (j > i) check karo.
2. Profit calculate karo (prices[j] - prices[i]).
3. Maximum profit update karo agar current profit bada ho.
4. Agar koi profit nahi mila, toh 0 return karo.

🕒 Time: O(n²)
💾 Space: O(1)
*/
int maxProfitBrute(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(prices[j] > prices[i]) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
    }
    return maxProfit;
}

// -------------------------------------------------
// ⚡ Optimal Approach (Single Pass)
// -------------------------------------------------
/*
📘 Steps:
1. Ek variable `minprices` rakho jo ab tak ka minimum price track kare.
2. Ek variable `maxprofit` rakho jo maximum profit store kare.
3. Har price ke liye:
   - Profit calculate karo (prices[i] - minprices).
   - `maxprofit` update karo agar current profit bada ho.
   - `minprices` update karo agar current price chhota ho.

🕒 Time: O(n)
💾 Space: O(1)
*/
int maxProfitOptimal(vector<int>& prices) {
    int minprices = prices[0]; // Initial min price
    int maxprofit = 0;

    for(int i = 1; i < prices.size(); i++) {
        int cost = prices[i] - minprices; // Calculate profit
        maxprofit = max(maxprofit, cost); // Update max profit
        minprices = min(prices[i], minprices); // Update min price
    }
    return maxprofit;
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};

    cout << "Input: prices = [7, 1, 5, 3, 6, 4]" << endl;
    cout << "Brute Force: " << maxProfitBrute(prices1) << endl;
    cout << "Optimal (Single Pass): " << maxProfitOptimal(prices1) << endl;

    cout << "\nInput: prices = [7, 6, 4, 3, 1]" << endl;
    cout << "Brute Force: " << maxProfitBrute(prices2) << endl;
    cout << "Optimal (Single Pass): " << maxProfitOptimal(prices2) << endl;

    return 0;
}
