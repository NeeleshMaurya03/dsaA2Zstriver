/*
💡 Problem: Find the Missing Number from 1 to N

🧠 Task:
Ek array diya gaya hai jisme 1 se N tak ke continuous numbers hone chahiye lekin ek number missing hai.
Tumhe woh missing number return karna hai.

📦 Input: arr = [1, 2, 4, 5]
🎯 Output: 3

🔐 Constraints:
1 ≤ arr.size() ≤ 10^6  
1 ≤ arr[i] ≤ arr.size() + 1
*/

#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------
// 🐢 Brute Force Approach
// --------------------------------------------
/*
🧾 Intuition:
1 se n tak ke sabhi numbers ke liye, array ke andar check karo ki woh number present hai ya nahi.
Jo number nahi milega, wahi answer hai.

📘 Steps:
1. Loop chalao i = 1 to n+1 tak.
2. Har i ke liye array ke andar search karo.
3. Agar nahi mila → return i

🕒 Time: O(n^2)
💾 Space: O(1)
*/
int missingNumberBrute(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i <= n + 1; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) return i;
    }
    return -1;
}

// --------------------------------------------
// 💼 Better Approach (Hashing)
// --------------------------------------------
/*
🧾 Intuition:
Ek extra array (hash) le lo jisme har number ka presence store karenge.
Jiska presence 0 hoga, wahi missing number hoga.

📘 Steps:
1. Ek vector banayo of size n+2 → kyuki loop me i <= n+1 jaa raha hai.
2. Array ke elements ko hash[arr[i]] = 1 mark karo.
3. Loop from i = 1 to n+1 → agar hash[i] == 0 → woh number missing hai.

🕒 Time: O(n)
💾 Space: O(n)
*/
int missingNumberHash(vector<int>& arr) {
    int n = arr.size();
    vector<int> hash(n + 2, 0); // +2 for safe access up to n+1

    for (int i = 0; i < n; i++) {
        hash[arr[i]] = 1;
    }

    for (int i = 1; i <= n + 1; i++) {
        if (hash[i] == 0) return i;
    }

    return -1;
}

// --------------------------------------------
// 🔥 Optimal Approach 1 (Sum Formula)
// --------------------------------------------
/*
🧾 Intuition:
1 se N tak ka total sum formula: n*(n+1)/2
Array ke actual sum se subtract kar do → wahi missing number hoga.

📘 Steps:
1. total sum = n*(n+1)/2
2. array ka sum nikalo
3. total - actual = missing

🕒 Time: O(n)
💾 Space: O(1)
*/
int missingNumberSum(vector<int>& arr) {
    int n = arr.size() + 1;
    long long total = 1LL * n * (n + 1) / 2;

    long long actual = 0;
    for (int num : arr) {
        actual += num;
    }

    return total - actual;
}

// --------------------------------------------
// 🔥 Optimal Approach 2 (XOR Method)
// --------------------------------------------
/*
🧾 Intuition:
XOR ka ek property hai:
- a^a = 0
- 0^a = a

Agar 1 se n tak ke sab elements aur array ke elements ka XOR nikaal lo,
Toh repeat hone wale cancel ho jayenge aur missing number bacha rahega.

📘 Steps:
1. 1 to n tak ka XOR nikaalo (xorFull)
2. Array ke elements ka XOR nikaalo (xorArr)
3. missing = xorFull ^ xorArr

🕒 Time: O(n)
💾 Space: O(1)
*/
int missingNumberXOR(vector<int>& arr) {
    int xorArr = 0, xorFull = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        xorArr ^= arr[i];     // XOR of array elements
        xorFull ^= (i + 1);   // XOR from 1 to n
    }

    xorFull ^= (n + 1);       // XOR of last number
    return xorArr ^ xorFull;
}

// --------------------------------------------
// 🔍 Driver Code
// --------------------------------------------
int main() {
    vector<int> arr = {1, 4, 3, 2}; // Missing number is 5

    cout << "Brute Force: " << missingNumberBrute(arr) << endl;
    cout << "Better (Hash): " << missingNumberHash(arr) << endl;
    cout << "Optimal 1 (Sum): " << missingNumberSum(arr) << endl;
    cout << "Optimal 2 (XOR): " << missingNumberXOR(arr) << endl;

    return 0;
}
