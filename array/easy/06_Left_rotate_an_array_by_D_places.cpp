/*
💡 Problem: Rotate an Array Left or Right by D positions

🧠 Task:
Ek array diya gaya hai aur ek number `d`, us array ko `d` jagah left ya right shift karna hai.

Examples:
Input:  [1, 2, 3, 4, 5, 6, 7], d = 2
Left Rotate → [3, 4, 5, 6, 7, 1, 2]
Right Rotate → [6, 7, 1, 2, 3, 4, 5]
*/


#include <iostream>
using namespace std;

// 🔁 Manual Reverse Function for Optimal
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start++], arr[end--]);
    }
}

/*-----------------------------------------------------
🐢 Approach 1: Brute Force using (i + (n - d)) % n

🧠 Explanation:
- Har element ko naya position mein daalo using formula.
- (i + (n - d)) % n ka matlab hota hai: left rotation.
- Kyuki left rotation = right shift by (n - d)

🕒 Time: O(n)
💾 Space: O(n)
-----------------------------------------------------*/
void leftRotateBrute(int arr[], int n, int d) {
    d = d % n; // handle d > n
    int temp[n];

    for (int i = 0; i < n; i++) {
        int newIndex = (i + (n - d)) % n;
        temp[newIndex] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

/*-----------------------------------------------------
⚡ Approach 2: Better (Using temp array of size d)

🧠 Explanation:
- First d elements ko store karo.
- Remaining (n-d) ko left shift karo.
- temp[] ke d elements ko end mein daal do.

🕒 Time: O(n)
💾 Space: O(d)
-----------------------------------------------------*/
void leftRotateBetter(int arr[], int n, int d) {
    d = d % n;
    int temp[d];

    // Step 1: Store first d elements
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Step 2: Shift remaining elements to the left
    for (int i = 0; i < n - d; i++) {
        arr[i] = arr[i + d];
    }

    // Step 3: Put temp[] elements at the end
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}

/*-----------------------------------------------------
🔥 Approach 3: Optimal (Reversal Algorithm)

🧠 Explanation:
- Reverse first d elements
- Reverse remaining (n-d) elements
- Reverse the entire array

🕒 Time: O(n)
💾 Space: O(1)
-----------------------------------------------------*/
void leftRotateOptimal(int arr[], int n, int d) {
    d = d % n;
    reverse(arr, 0, d - 1);      // Reverse first d
    reverse(arr, d, n - 1);      // Reverse rest
    reverse(arr, 0, n - 1);      // Reverse all
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
    int d = 9;  // Rotate more than size → d = 9 % 7 = 2

    leftRotateBrute(arr1, n, d);
    leftRotateBetter(arr2, n, d);
    leftRotateOptimal(arr3, n, d);

    cout << "Brute Force: ";  printArray(arr1, n);
    cout << "Better:      ";  printArray(arr2, n);
    cout << "Optimal:     ";  printArray(arr3, n);

    return 0;
}
