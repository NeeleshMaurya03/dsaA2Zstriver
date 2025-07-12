/*
💡 Problem: Longest Subarray with Sum = K (Positive + Negative Elements Allowed)

🧠 Task:
Ek array diya gaya hai jisme positive, negative aur 0 values ho sakti hain.
Longest subarray ka length find karo jiska total sum exactly K ho.

🎯 Example:
Input: arr = {1, 2, 3, -2, 5}, K = 5
Output: 4  (subarray = [2, 3, -2, 2])

📘 Approach: Prefix Sum + Hash Map
1. Har index tak ka sum calculate karo.
2. Map me sum store karo with its first occurrence index.
3. Jab bhi sum - K already map me ho, iska matlab beech ka sum = K.
4. Max length update karte jao.

Time: O(n)
Space: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarraySumK(vector<int>& arr, int k) {
    unordered_map<int, int> prefixMap; // sum -> first index
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Agar sum == k, to start se lekar yahan tak ka subarray valid
        if (sum == k) {
            maxLen = i + 1;
        }

        // sum - k pehle kab mila tha? agar mila toh length update karo
        if (prefixMap.find(sum - k) != prefixMap.end()) {
            int len = i - prefixMap[sum - k];
            maxLen = max(maxLen, len);
        }

        // Har sum ka first occurrence store karo (not overwrite)
        if (prefixMap.find(sum) == prefixMap.end()) {
            prefixMap[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    // ✅ Example Input:
    vector<int> arr = {1, 2, 3, -2, 2, 5, -1};
    int k = 5;

    int ans = longestSubarraySumK(arr, k);

    // 🖨️ Output:
    cout << "Longest Subarray Length with Sum = " << k << " is: " << ans << endl;

    return 0;
}
