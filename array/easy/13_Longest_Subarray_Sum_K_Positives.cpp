/*
💡 Problem: Longest Subarray with Sum = K (Positive Integers Only)

🧠 Task:
Ek array diya gaya hai aur ek value K.
Longest length wali subarray dhoondo jiska sum exactly K ho.

📦 Input:
arr = [1, 2, 1, 0, 1, 1, 0], K = 4
🎯 Output: 4 (subarray: [1, 2, 1, 0])
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Nested Loops)
// -------------------------------------------------
/*
📘 Steps:
1. Har index se start karke sum calculate karo.
2. Jab tak sum == k nahi hota tab tak loop chalao.
3. Jab mile toh maxLength update karo.

🕒 Time: O(n²)
💾 Space: O(1)
*/
int longestSubarrayBrute(vector<int>& arr, int k) {
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// -------------------------------------------------
// 💼 Better Approach (Prefix Sum + Hash Map)
// -------------------------------------------------
/*
📘 Steps:
1. Prefix sum calculate karo har index tak.
2. Ek map banao: sum → first index.
3. Har step pe:
   - Agar sum == k ho gaya, maxLen = i+1
   - Agar (sum - k) map me hai, matlab beech me ek valid subarray mila.
     uska length nikaalo aur maxLen update karo.

🕒 Time: O(n)
💾 Space: O(n)
*/
int longestSubarrayPrefixSum(vector<int>& arr, int k) {
    unordered_map<int, int> prefixMap;  // sum -> index
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Full subarray from start
        if (sum == k) {
            maxLen = i + 1;
        }

        // subarray with sum = k exists between indices
        if (prefixMap.find(sum - k) != prefixMap.end()) {
            int len = i - prefixMap[sum - k];
            maxLen = max(maxLen, len);
        }

        // Store only the first occurrence
        if (prefixMap.find(sum) == prefixMap.end()) {
            prefixMap[sum] = i;
        }
    }

    return maxLen;
}

// -------------------------------------------------
// ⚡ Optimal Approach (2 Pointer Sliding Window)
// -------------------------------------------------
/*
📘 Steps:
1. Two pointers: left = 0, right = 0
2. Expand right and keep adding to sum.
3. If sum > k → left se shrink karo
4. If sum == k → maxLen update karo

⚠️ Note: Works only if all elements are **positive**

🕒 Time: O(n)
💾 Space: O(1)
*/
int longestSubarrayTwoPointer(vector<int>& arr, int k) {
    int left = 0, right = 0;
    int sum = 0, maxLen = 0;

    while (right < arr.size()) {
        sum += arr[right];

        while (sum > k) {
            sum -= arr[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    return maxLen;
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> arr = {1, 2, 1, 0, 1, 1, 0};
    int k = 4;

    cout << "Brute Force: " << longestSubarrayBrute(arr, k) << endl;
    cout << "Better (Prefix Sum + Map): " << longestSubarrayPrefixSum(arr, k) << endl;
    cout << "Optimal (2 Pointer): " << longestSubarrayTwoPointer(arr, k) << endl;

    return 0;
}
