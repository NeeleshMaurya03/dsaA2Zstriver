/*
💡 Problem: Find the Union of Two Sorted Arrays

🧠 Task:
Given two **sorted arrays** `a` and `b`, find their union.
Union means all **unique elements** present in either `a` or `b`.

🔸 Example:
Input:
a = [1, 2, 2, 3, 4]
b = [2, 3, 5]

Output: [1, 2, 3, 4, 5]
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// ---------------------------------------------
// 🐢 Brute Force Approach (Using Set and Simple Loop)
// ---------------------------------------------
/*
🔹 Steps:
1. Create an empty set `s` (which stores only unique elements).
2. Traverse both arrays using regular loops.
3. Insert each element into the set.
4. Convert set into vector and return.

🕒 Time: O(n1 log n) + O(n2 log n) —> insertion in set + O(n+m) pushing bak to array
   where n1 and n2 are sizes of arrays a and b. (doubt 🤔)

💾 Space: O(n + m) — due to set
*/
vector<int> findUnionBrute(vector<int> &a, vector<int> &b) {
    set<int> s;

    // Insert elements of first array
    for (int i = 0; i < a.size(); i++) {
        s.insert(a[i]);
    }

    // Insert elements of second array
    for (int i = 0; i < b.size(); i++) {
        s.insert(b[i]);
    }

    // Convert set to vector
    vector<int> result;
    for (auto it = s.begin(); it != s.end(); it++) {
        result.push_back(*it);
    }

    return result;
}


// --------------------------------------------------------
// 🔥 Optimal Approach (Using Two Pointers)
// --------------------------------------------------------
/*
🔹 Intuition:
Since arrays are sorted, we can merge them while ignoring duplicates using two pointers.

🔹 Steps:
1. Initialize i and j at 0.
2. While both i and j are in bounds:
   - If a[i] < b[j], insert a[i] if it’s not duplicate.
   - If b[j] < a[i], insert b[j] if it’s not duplicate.
   - If equal, insert once and move both i & j.
3. Add remaining elements from either array similarly.

🕒 Time: O(n + m)
💾 Space: O(1) extra (excluding result)
*/
vector<int> findUnionOptimal(vector<int> &a, vector<int> &b) {
    vector<int> unionarr;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (unionarr.empty() || unionarr.back() != a[i])
                unionarr.push_back(a[i]);
            i++;
        } else if (b[j] < a[i]) {
            if (unionarr.empty() || unionarr.back() != b[j])
                unionarr.push_back(b[j]);
            j++;
        } else {
            // a[i] == b[j]
            if (unionarr.empty() || unionarr.back() != a[i])
                unionarr.push_back(a[i]);
            i++;
            j++;
        }
    }

    // Add remaining from a[]
    while (i < a.size()) {
        if (unionarr.empty() || unionarr.back() != a[i])
            unionarr.push_back(a[i]);
        i++;
    }

    // Add remaining from b[]
    while (j < b.size()) {
        if (unionarr.empty() || unionarr.back() != b[j])
            unionarr.push_back(b[j]);
        j++;
    }

    return unionarr;
}


// ---------------------
// 🔍 Driver Code
// ---------------------
int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 5};

    // Brute Force Result
    vector<int> bruteResult = findUnionBrute(a, b);
    cout << "Brute (Set) Union: ";
    for (int i = 0; i < bruteResult.size(); i++) {
        cout << bruteResult[i] << " ";
    }
    cout << endl;

    // Optimal Result
    vector<int> optResult = findUnionOptimal(a, b);
    cout << "Optimal (2-pointer) Union: ";
    for (int i = 0; i < optResult.size(); i++) {
        cout << optResult[i] << " ";
    }
    cout << endl;

    return 0;
}
