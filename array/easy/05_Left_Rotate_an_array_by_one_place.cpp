/*
💡 Problem: Left Rotate an Array by One Place

🧠 Task:
Ek array diya gaya hai. Usme se har element ko ek position left shift karna hai.
Pehla element last mein chala jaayega.

Example:
Input:  [1, 2, 3, 4, 5]
Output: [2, 3, 4, 5, 1]
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    // 🐢 Brute Force Approach:
    // ➤ Ek naya vector banao, har element ko 1 position left shift karo
    // ➤ Last element mein pehla element daal do
    // Time: O(n), Space: O(n)
    vector<int> rotated;
    for (int i = 1; i < arr.size(); i++) {
        rotated.push_back(arr[i]);
    }
    rotated.push_back(arr[0]);

    cout << "Brute Left Rotated Array: ";
    for (int num : rotated) {
        cout << num << " ";
    }
    cout << endl;

    // 🔥 Optimal Approach (In-place):
    // ➤ Pehle element ko temporary variable mein store karo
    // ➤ Har element ko uske aage wale ki value se replace karo
    // ➤ Last element mein temp daal do
    // Time: O(n), Space: O(1)
    int temp = arr[0];
    for (int i = 0; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = temp;

    cout << "Optimal Left Rotated Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
