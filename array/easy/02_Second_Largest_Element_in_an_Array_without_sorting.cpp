/*
💡 Problem: Find the Second Largest Element in an Array

🧠 Task:
Ek array diya gaya hai, usme se second largest (dusra sabse bada) element nikaalna hai.
Jaise: [10, 5, 20, 8, 25] → Answer: 20
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // input array
    vector<int> arr = {10, 5, 20, 8, 25};

    // 🐢 Brute Force Approach:
    // > Array ko sort karo increasing order mein
    // > Last element largest hoga, uske pehle jo pehla unique chhota element mile, wahi second largest hoga
    // > ⚠️ Agar array mein duplicate max elements hon (e.g. [10, 10, 5]), toh unko skip karke second largest dhoondhna hoga
    // > ⚠️ Edge Case: Agar sab elements same hain → second largest exist hi nahi karega → return -1
    // 🕒 Time: O(n log n)
    // 💾 Space: O(1)
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());

    int n = temp.size();
    int secondLargest = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (temp[i] != temp[n - 1]) { // unique chhota element
            secondLargest = temp[i];
            break;
        }
    }
    cout << "🐢 Brute Approach → Second Largest: " << secondLargest << endl;

    // ⚡ Better Approach:
    // Step 1: Pehle maximum element dhoondo (max1)
    // Step 2: Phir ek aur baar loop chalao aur max1 se chhota sabse bada element (second max) dhoondo
    // 🕒 Time: O(2n)
    // 💾 Space: O(1)
    int max1 = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }

    int second = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != max1) {
            if (second == -1 || arr[i] > second) {
                second = arr[i];
            }
        }
    }
    cout << "⚡ Better Approach → Second Largest: " << second << endl;

    // 🔥 Optimal Approach (1-pass):
    // ✅ Smart Idea:
    //    Jab bhi koi element current max se bada mile → matlab ek aur naya bada element mila
    //    ➤ Toh purana max auto-second largest ban jaata hai
    //    ➤ Isliye: second largest = first largest, then first largest = arr[i]
    //
    //    Agar element first se chhota ho lekin second se bada ho → second = arr[i]
    //
    // Example: [10, 5, 20, 8, 25]
    //    first = 10, second = -1
    //    5 → chhota → skip
    //    20 > 10 → first = 20, second = 10 ajana chaiy automatically
    //    8 → chhota → skip
    //    25 > 20 → first = 25, second = 20
    //
    // 🕒 Time: O(n)
    // 💾 Space: O(1)
    int first = arr[0];
    int sec = -1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > first) {
            // 🟢 Naya largest mila → first jo tha ab second largest ban gaya
            sec = first;
            first = arr[i];
        } else if (arr[i] < first && arr[i] > sec) {
            // 🟡 second largest ke liye update condition kyunki last elent upr wale se nhi mil skta 
            sec = arr[i];
        }
    }

    cout << "🔥 Optimal Approach → Second Largest: " << sec << endl;

    return 0;
}
