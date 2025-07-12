/*
💡 Problem: Maximum Consecutive 1's in a Binary Array

🧠 Task:
Ek binary array diya gaya hai (sirf 0 aur 1).
Tumhe batana hai ki sabse lambi continuous 1s ki sequence kitni hai.

📦 Input: arr = [1, 1, 0, 1, 1, 1]
🎯 Output: 3 (kyunki 1,1,1 continuously aaye)

🔐 Constraints:
1 ≤ arr.size() ≤ 10^6  
arr[i] = 0 ya 1
*/

#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------
// ⚡ Optimal Approach (Single Pass)
// --------------------------------------------
/*
🧾 Intuition:
Agar 1 milta rahe toh count++ karo
Jaise hi 0 mile, count reset kardo.
Har step pe max count update karte raho.

📘 Steps:
1. Ek count aur maxCount variable banao
2. Array traverse karo:
   - Agar 1 mile → count++
   - Agar 0 mile → count = 0
   - Har step pe maxCount update karo

🕒 Time: O(n)
💾 Space: O(1)
*/
int maxConsecutiveOnes(vector<int>& arr) {
    int count = 0, maxCount = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }

    return maxCount;
}

// --------------------------------------------
// 🔍 Driver Code
// --------------------------------------------
int main() {
    vector<int> arr = {1, 1, 0, 1, 1, 1}; // Longest 1s = 3

    cout << "Maximum Consecutive 1s: " << maxConsecutiveOnes(arr) << endl;

    return 0;
}
