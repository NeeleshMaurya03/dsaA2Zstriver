/*
💡 Problem: Sort 0s, 1s, 2s (Dutch National Flag)

🧠 Task:
Ek array diya gaya hai jisme sirf 0s, 1s, aur 2s hain.
Inko sort karo (0s first, then 1s, then 2s).

🧪 Example:
Input: arr = [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Sorting)
// -------------------------------------------------
/*
📘 Steps:
1. Array ko built-in sort function se sort kar do.
2. Sab 0s left pe, 1s beech mein, aur 2s right pe aa jayenge.

🕒 Time: O(n log n)
💾 Space: O(1)
*/
void sort012Brute(vector<int>& arr) {
    sort(arr.begin(), arr.end()); // Built-in sort
}

// -------------------------------------------------
// 💼 Better Approach (Using Counter)
// -------------------------------------------------
/*
📘 Steps:
1. Ek counter se 0s, 1s, aur 2s ki count nikaalo.
2. Fir array ko overwrite karo: pehle 0s, then 1s, then 2s.

🕒 Time: O(n) (do passes)
💾 Space: O(1)
*/
void sort012Counter(vector<int>& arr) {
    int count0 = 0, count1 = 0, count2 = 0;
    // Count 0s, 1s, 2s
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }
    // Overwrite array
    int i = 0;
    while(count0--) arr[i++] = 0;
    while(count1--) arr[i++] = 1;
    while(count2--) arr[i++] = 2;
}

// -------------------------------------------------
// ⚡ Optimal Approach (Dutch National Flag)
// -------------------------------------------------
/*
📘 Steps:
1. Teen pointers rakho: low, mid, high.
   - low se pehle sab 0s, high ke baad sab 2s, aur beech mein 1s.
2. Mid pointer ko traverse karo:
   - Agar arr[mid] == 0: Swap with low, low++, mid++.
   - Agar arr[mid] == 1: Mid++.
   - Agar arr[mid] == 2: Swap with high, high--.

🕒 Time: O(n) (single pass)
💾 Space: O(1)
*/
void sort012Dutch(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    vector<int> arr1 = arr, arr2 = arr; // Copies for testing all approaches

    cout << "Input: arr = [2, 0, 2, 1, 1, 0]" << endl;

    cout << "Brute Force (Sorting): ";
    sort012Brute(arr);
    for(int x : arr) cout << x << " ";
    cout << endl;

    cout << "Better (Counter): ";
    sort012Counter(arr1);
    for(int x : arr1) cout << x << " ";
    cout << endl;

    cout << "Optimal (Dutch National Flag): ";
    sort012Dutch(arr2);
    for(int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}