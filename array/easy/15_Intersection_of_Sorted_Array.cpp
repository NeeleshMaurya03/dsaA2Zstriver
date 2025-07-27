/*
💡 Problem: Intersection of Two Sorted Arrays

🧠 Task:
Do sorted arrays a aur b diye gaye hain, dono mein duplicates ho sakte hain. Inka intersection return karna hai, yani ek sorted array jisme sirf common elements hon, with duplicates as per common occurrences.

🔸 Examples:
Input: a = [1, 2, 2, 3, 4], b = [2, 3, 5]
Output: [2, 3]
Explanation: 2 aur 3 common hain, 2 ek baar common (b mein ek hi 2).

Input: a = [1, 1, 2, 2], b = [1, 1, 2, 2]
Output: [1, 1, 2, 2]
Explanation: 1 do baar common, 2 do baar common.

Input: a = [1, 2], b = [3, 4]
Output: []
Explanation: No common elements.

📝 Constraints:
- 1 <= a.size(), b.size() <= 10^5
- Arrays sorted in ascending order
- Elements can be positive, negative, or zero
- Output must be sorted, duplicates as per common occurrences
*/

#include <iostream>
#include <vector>
using namespace std;

/*-----------------------------------------------------
🐢 Approach 1: Brute Force (Nested Loop)

🧠 Explanation:
- Har element of a ko b mein linearly search karo.
- Agar element milta hai, aur woh pehle nahi liya gaya, toh result mein add karo.
- Duplicates handle karne ke liye, visited elements ko mark karo (ya skip karo).
- Edge cases handle karo (empty arrays).

🕒 Time: O(n1 * n2) - n1 iterations mein har ek ke liye n2 search.
💾 Space: O(n2) - Visited array ya result vector ke liye.
-----------------------------------------------------*/
vector<int> intersectionBrute(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    // Step 1: Edge cases
    if (n1 == 0 || n2 == 0) {
        return {};
    }

    // Step 2: Mark visited elements in b
    vector<bool> visited(n2, false);
    vector<int> result;

    // Step 3: Iterate through a and search in b
    for (int i = 0; i < n1; i++) {
        // Skip duplicates in a
        if (i > 0 && a[i] == a[i-1]) {
            continue;
        }
        for (int j = 0; j < n2; j++) {
            if (!visited[j] && a[i] == b[j]) {
                result.push_back(a[i]);
                visited[j] = true;
                break; // Found match, move to next element in a
            }
        }
    }

    return result;
}

/*-----------------------------------------------------
🔥 Approach 2: Optimal (Two-Pointer Approach)

🧠 Explanation:
- Do pointers use karo: i (a ke liye), j (b ke liye).
- Dono arrays sorted hain, toh compare karo aur common elements add karo.
- Duplicates handle karo by moving pointers carefully.
- Jab ek array exhaust ho jaye, stop karo.
- Edge cases handle karo.

🕒 Time: O(n1 + n2) - Single pass through both arrays.
💾 Space: O(min(n1, n2)) - Output vector ke liye (return ke liye).
-----------------------------------------------------*/
vector<int> intersectionOptimal(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    // Step 1: Edge cases
    if (n1 == 0 || n2 == 0) {
        return {};
    }

    // Step 2: Initialize pointers and result
    int i = 0, j = 0;
    vector<int> result;

    // Step 3: Compare elements using two pointers
    while (i < n1 && j < n2) {
        if (a[i] == b[j]) {
            // Add to result if it's the first occurrence or different from last added
            if (result.empty() || a[i] != result.back()) {
                result.push_back(a[i]);
            }
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}

// 🖨️ Utility to print array
void printArray(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// 🚀 Main Function
int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 5};
    vector<int> result1 = intersectionBrute(a, b);
    vector<int> result2 = intersectionOptimal(a, b);

    cout << "Brute Force: "; printArray(result1);
    cout << "Optimal:     "; printArray(result2);

    return 0;
}