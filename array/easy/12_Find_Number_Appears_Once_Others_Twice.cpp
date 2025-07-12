/*
💡 Problem: Find the number that appears once, while others appear twice

🧠 Task:
Ek array diya gaya hai jisme har number 2 baar aata hai, except ek number jo sirf 1 baar aata hai.
Us number ko dhoondho.

📦 Input: arr = [4, 1, 2, 1, 2]
🎯 Output: 4

🔐 Constraints:
1 ≤ arr.size() ≤ 10^6
-10^9 ≤ arr[i] ≤ 10^9
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Nested Loop)
// -------------------------------------------------
/*
📘 Steps:
1. Har element ke liye count check karo using nested loops.
2. Agar count 1 ho toh return that element.

🕒 Time: O(n^2)
💾 Space: O(1)
*/
int singleNumberBrute(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count == 1) return arr[i];
    }
    return -1;
}

// -------------------------------------------------
// 💼 Better 1: Using Frequency Hash Array (Hashing)
// -------------------------------------------------
/*
📘 Steps:
1. Find max element to size the hash array.
2. Count frequency using array.
3. Return the element whose count is 1.

⚠️ Only works if values are small & positive.

🕒 Time: O(n)
💾 Space: O(max(arr[i]))
*/
int singleNumberHashing(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> hash(maxVal + 1, 0);

    for (int i = 0; i < arr.size(); i++) {
        hash[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (hash[arr[i]] == 1) return arr[i];
    }

    return -1;
}

// -------------------------------------------------
// 💼 Better 2: Using Map (Frequency Count)
// -------------------------------------------------
/*
📘 Steps:
1. Use map to count freq of elements.
2. Return the key with value 1.

🕒 Time: O(n log n)
💾 Space: O(n)
*/
int singleNumberMap(vector<int>& arr) {
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++) {
        mpp[arr[i]]++;
    }

    for (auto it : mpp) {
        if (it.second == 1) return it.first;
    }

    return -1;
}

// -------------------------------------------------
// ⚡ Optimal Approach: Using XOR
// -------------------------------------------------
/*
📘 Steps:
1. Initialize xor = 0.
2. XOR all elements → duplicates cancel out.
3. Only unique element remains.

🕒 Time: O(n)
💾 Space: O(1)
*/
int singleNumberXOR(vector<int>& arr) {
    int xorr = 0;
    for (int num : arr) {
        xorr ^= num;
    }
    return xorr;
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> arr = {4, 1, 2, 1, 2}; // Unique = 4

    cout << "Brute Force: " << singleNumberBrute(arr) << endl;
    cout << "Better 1 (Hashing): " << singleNumberHashing(arr) << endl;
    cout << "Better 2 (Map): " << singleNumberMap(arr) << endl;
    cout << "Optimal (XOR): " << singleNumberXOR(arr) << endl;

    return 0;
}
