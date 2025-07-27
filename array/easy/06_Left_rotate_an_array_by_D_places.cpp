/*
💡 Problem: Rotate an Array Left or Right by D Positions

🧠 Task:
Ek array diya gaya hai aur ek number `d`, us array ko `d` jagah left ya right shift karna hai.

🔸 Examples:
Input:  [1, 2, 3, 4, 5, 6, 7], d = 2
Left Rotate → [3, 4, 5, 6, 7, 1, 2]
Right Rotate → [6, 7, 1, 2, 3, 4, 5]

Input:  [1, 2, 3, 4, 5, 6, 7], d = 9
Left Rotate → [3, 4, 5, 6, 7, 1, 2] (kyunki 9 % 7 = 2)
Right Rotate → [6, 7, 1, 2, 3, 4, 5] (kyunki 9 % 7 = 2)

📝 Constraints:
- 1 <= n <= 10^5 (array size)
- 0 <= d <= 10^9
- In-place modification preferred
*/

#include <iostream>
using namespace std;

// 🔁 Manual Reverse Function for Optimal
void reverse(int arr[], int start, int end) {
    // Swap elements from start to end until they meet
    while (start < end) {
        swap(arr[start++], arr[end--]);
    }
}

/*-----------------------------------------------------
🐢 Approach 1: Brute Force (Temp Array of Size d)

🧠 Explanation:
- Pehle d elements ko temp array mein store karo.
- Baaki (n-d) elements ko d positions left shift karo (arr[i] = arr[i+d]).
- Temp ke d elements ko array ke end mein daal do (arr[n-d...n-1]).
- Edge cases handle karo (n <= 1, d == 0, d > n).
- Yeh brute force hai kyunki O(d) extra space use hota hai.

🕒 Time: O(n) - O(d) for temp, O(n-d) for shift, O(d) for copying back.
💾 Space: O(d) - Temp array of size d.
-----------------------------------------------------*/
void leftRotateBrute(int arr[], int n, int d) {
    // Step 1: Edge cases
    if (n <= 1) return; // No rotation needed for empty or single element
    d = d % n; // Handle d > n
    if (d == 0) return; // No rotation needed

    // Step 2: Store first d elements in temp
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i]; // Copy arr[0...d-1] to temp
    }

    // Step 3: Shift remaining elements to the left
    for (int i = 0; i < n - d; i++) {
        arr[i] = arr[i + d]; // arr[i+d] ko arr[i] pe copy karo
    }

    // Step 4: Put temp elements at the end
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i]; // Copy temp to arr[n-d...n-1]
    }
}

/*-----------------------------------------------------
🔥 Approach 2: Optimal (Reversal Algorithm)

🧠 Explanation:
- Reverse first d elements: arr[0...d-1].
- Reverse remaining (n-d) elements: arr[d...n-1].
- Reverse entire array: arr[0...n-1].
- Yeh in-place hai aur koi extra array nahi use hota.
- Edge cases handle karo.

🕒 Time: O(n) - O(d) for first reverse, O(n-d) for second, O(n) for full array.
💾 Space: O(1) - In-place, sirf swap ke liye constant space.
-----------------------------------------------------*/
void leftRotateOptimal(int arr[], int n, int d) {
    // Step 1: Edge cases
    if (n <= 1) return;
    d = d % n;
    if (d == 0) return;

    // Step 2: Three reversals
    reverse(arr, 0, d - 1); // Reverse first d elements
    reverse(arr, d, n - 1); // Reverse remaining n-d elements
    reverse(arr, 0, n - 1); // Reverse entire array
}

/*-----------------------------------------------------
🔄 Follow-Up: Right Rotate by D Positions

🧠 Explanation:
- Right rotate = left rotate by (n - d).
- Same reversal algorithm, but order alag:
  1. Reverse entire array.
  2. Reverse first d elements.
  3. Reverse remaining n-d elements.

🕒 Time: O(n)
💾 Space: O(1)
-----------------------------------------------------*/
void rightRotateOptimal(int arr[], int n, int d) {
    // Step 1: Edge cases
    if (n <= 1) return;
    d = d % n;
    if (d == 0) return;

    // Step 2: Three reversals
    reverse(arr, 0, n - 1); // Reverse entire array
    reverse(arr, 0, d - 1); // Reverse first d elements
    reverse(arr, d, n - 1); // Reverse remaining n-d elements
}

// 🖨️ Utility to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// 🚀 Main Function
int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int arr3[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int d = 9; // Effective d = 9 % 7 = 2

    // Test both approaches
    leftRotateBrute(arr1, n, d);
    leftRotateOptimal(arr2, n, d);
    rightRotateOptimal(arr3, n, d);

    cout << "Brute Force (Left):  "; printArray(arr1, n);
    cout << "Optimal (Left):     "; printArray(arr2, n);
    cout << "Optimal (Right):    "; printArray(arr3, n);

    return 0;
}
