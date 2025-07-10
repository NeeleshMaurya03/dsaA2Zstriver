/*
💡 Problem: Move all Zeros to the End of the Array

🧠 Task:
Ek array diya gaya hai, jisme kuch 0 ho sakte hain.
Aapko saare 0 ko array ke end me shift karna hai,
lekin baaki non-zero elements ki ordering same rehni chahiye.

🔸 Example 1:
Input:  arr = [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]

🔸 Example 2:
Input:  arr = [1, 0, 2, 3, 0, 4]
Output: [1, 2, 3, 4, 0, 0]
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 5};
    int n = arr.size();

    // ---------------------------------------------
    // 🐢 Brute Force Approach (with temp array):
    // Step 1: Ek temporary array banao.
    // Step 2: Pehle saare non-zero elements daalo.
    // Step 3: Baaki jagah 0 se fill karo.
    // 🕒 Time: O(n)
    // 💾 Space: O(n)
    // ---------------------------------------------

    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            temp.push_back(arr[i]);
    }

    while (temp.size() < n)
        temp.push_back(0);

    cout << "Brute Force Result: ";
    for (int val : temp) cout << val << " ";
    cout << endl;

    // ---------------------------------------------
    // 🔥 Optimal Approach (Using Two Pointers):
    // 1. j pointer: pehle 0 element ko point karega.
    // 2. i pointer: uske baad se traverse karega.
    // 3. Jab bhi i par non-zero mile, i aur j ko swap kar do aur j++
    // 4. Isse non-zero elements left mein aate jaayenge, 0s automatically right mein chale jaayenge.

    // 🕒 Time Complexity: O(n)
    // 💾 Space Complexity: O(1) (In-place)
    // ---------------------------------------------

    vector<int> arr2 = {1, 0, 2, 3, 0, 4, 0, 5};
    int j = -1;

    // j = first zero index
    for (int i = 0; i < n; i++) {
        if (arr2[i] == 0) {
            j = i;
            break;
        }
    }

    // Agar j -1 hai, matlab koi 0 nahi mila
    if (j != -1) { // Agar array mein koi 0 nahi hua tb below code nhi chlega
        for (int i = j + 1; i < n; i++) {
            if (arr2[i] != 0) {
                swap(arr2[i], arr2[j]);
                j++;
            }
        }
    }

    cout << "Optimal Result:     ";
    for (int val : arr2) cout << val << " ";
    cout << endl;

    return 0;
}
