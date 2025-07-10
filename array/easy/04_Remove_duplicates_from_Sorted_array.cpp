/*
💡 Problem: Remove Duplicates from a Sorted Array

🧠 Task:
Ek sorted array diya gaya hai jisme duplicate elements ho sakte hain.
Aapko unique elements nikaalne hain, aur unko left side mein shift karna hai.
Final array mein koi duplicate nahi hona chahiye.

🔸 Example:
Input:  [1, 1, 2, 2, 3, 3, 3]
Output: [1, 2, 3]
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    // Input array
    vector<int> arr = {1, 1, 2, 2, 3, 3, 3};
    int n = arr.size();

    // ----------------------------------
    // 🐢 Brute Force using Set
    // ----------------------------------
    // Set unique elements ko store karta hai
    // Internally balanced BST (Red-Black Tree) hota hai
    // Sorted order maintain karta hai
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);  // O(log n) per insert
    }

    cout << "Brute Force (Set): ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;
    // Time: O(n log n), Space: O(n)

    // ----------------------------------
    // 🛠️ Better Approach using Temp Vector
    // ----------------------------------
    // Sorted array mein duplicate elements side-by-side hote hain
    // Compare karo current element ko previous se
    // Agar different hai to unique hai, temp mein daalo
    vector<int> temp;
    temp.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            temp.push_back(arr[i]);
        }
    }

    cout << "Better (Temp Vector): ";
    for (int val : temp) {
        cout << val << " ";
    }
    cout << endl;
    // Time: O(n), Space: O(n)

    // ----------------------------------
    // 🔥 Optimal Approach (In-place using 2 Pointers)
    // ----------------------------------
    // i → last unique element ka index
    // j → traversal pointer
    // Jab bhi naya unique mile, use i+1 wali position par rakh do
    // Final unique elements honge: arr[0] to arr[i]

    vector<int> arr2 = {1, 1, 2, 2, 3, 3, 3};
    int i = 0;

    for (int j = 1; j < arr2.size(); j++) {
        if (arr2[j] != arr2[i]) {
            i++;               // next position for unique element
            arr2[i] = arr2[j]; // overwrite current position
        }
    }

    cout << "Optimal (In-place): ";
    for (int k = 0; k <= i; k++) {
        cout << arr2[k] << " ";
    }
    cout << endl;
    // Time: O(n), Space: O(1)

    return 0;
}
