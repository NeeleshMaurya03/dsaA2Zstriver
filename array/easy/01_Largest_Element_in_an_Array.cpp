/*
💡 Problem: Find the Largest Element in an Array

🧠 Task:
Ek array diya gaya hai, usme se sabse bada element nikaalna hai.
Jaise: [10, 5, 20, 8, 25] → Answer: 25
*/

#include <bits/stdc++.h>
using namespace std;
int main() {

// 🐢 Brute Force Approach:
//  > Array ko sort karo
//  > Last element will be largest
// 🕒 Time: O(n log n)
// 💾 Space: O(1) (depends on sorting algo)
   

// input array
    vector<int> arr = {10, 5, 20, 8, 25};

    sort(arr.begin(), arr.end());
    cout << "Largest Element: " << arr[arr.size() - 1] << endl;

// 🔥 Optimal Approach:

// > Ek variable lo maxElement, start with arr[0]
// > Traverse array, agar koi element bada mile toh max update kar do
// 🕒 Time: O(n)
// 💾 Space: O(1)

    int maxElement = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    cout << "Largest Element: " << maxElement << endl;

    return 0;
}