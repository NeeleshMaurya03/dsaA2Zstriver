/*
💡 Problem: Linear Search in an Array

🧠 Task:
Ek array diya gaya hai aur ek target x.
Check karo x array mein hai ya nahi.
Agar hai toh index return karo, warna -1.

🔸 Example 1:
Input:  arr = [5, 10, 15, 20], x = 15
Output: Element found at index 2

🔸 Example 2:
Input:  arr = [1, 3, 5], x = 8
Output: Element not found
*/

#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
