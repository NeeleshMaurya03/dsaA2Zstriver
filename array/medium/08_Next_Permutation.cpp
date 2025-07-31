/*
💡 Problem: Next Permutation

🧠 Task:
Ek array diya gaya hai jo ek permutation represent karta hai.
Iska next lexicographically greater permutation find karo.
Agar next permutation possible nahi, toh smallest permutation (sorted order) return karo.

🧪 Example:
Input: arr = [1, 2, 3]
Output: [1, 3, 2]

Input: arr = [3, 2, 1]
Output: [1, 2, 3]

Input: arr = [1, 1, 5]
Output: [1, 5, 1]
*/

#include <iostream>
#include <vector>
#include <algorithm> // For STL next_permutation
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Recursion)
// -------------------------------------------------
/*
📘 Steps:
1. Saare possible permutations generate karo using recursion.
2. Diya hua permutation find karo aur uska agla permutation return karo.
3. Agar last permutation hai, toh pehla permutation (sorted order) return karo.

🕒 Time: O(n!) (saare permutations generate karne ke liye)
💾 Space: O(n!) (recursion stack aur permutations store karne ke liye)
*/
void generatePermutations(vector<int>& arr, vector<int>& temp, vector<vector<int>>& allPerms, vector<bool>& used) {
    if(temp.size() == arr.size()) {
        allPerms.push_back(temp);
        return;
    }
    for(int i = 0; i < arr.size(); i++) {
        if(!used[i]) {
            used[i] = true;
            temp.push_back(arr[i]);
            generatePermutations(arr, temp, allPerms, used);
            temp.pop_back();
            used[i] = false;
        }
    }
}

vector<int> nextPermutationBrute(vector<int>& arr) {
    vector<vector<int>> allPerms;
    vector<int> temp;
    vector<bool> used(arr.size(), false);
    generatePermutations(arr, temp, allPerms, used);
    sort(allPerms.begin(), allPerms.end()); // Lexicographical order

    // Find current permutation
    for(int i = 0; i < allPerms.size(); i++) {
        if(allPerms[i] == arr) {
            // Return next permutation or first if last
            if(i == allPerms.size() - 1) return allPerms[0];
            return allPerms[i + 1];
        }
    }
    return arr; // Fallback (should not reach here)
}

// -------------------------------------------------
// 🦁 Better Approach (STL Library)
// -------------------------------------------------
/*
📘 Steps:
1. STL ke `next_permutation` function ka use karo.
2. Yeh function array ko in-place modify karta hai to next permutation banaye.
3. Agar next permutation nahi hai, toh array ko sorted order mein karta hai.

🕒 Time: O(n)
💾 Space: O(1)
*/
vector<int> nextPermutationBetter(vector<int>& arr) {
    vector<int> result = arr;
    next_permutation(result.begin(), result.end());
    return result;
}

// -------------------------------------------------
// ⚡ Optimal Approach (Manual Implementation)
// -------------------------------------------------
/*
📘 Steps:
1. Right se traverse karo aur pehla index `i` find karo jahan arr[i] < arr[i+1] (dip point).
2. Agar aisa `i` nahi mila, toh pura array reverse karo (last permutation).
3. Warna, right se ek index `j` find karo jahan arr[j] > arr[i].
4. arr[i] aur arr[j] swap karo.
5. i+1 se end tak ke elements reverse karo.

🕒 Time: O(n)
💾 Space: O(1)

📜 How STL `next_permutation` Works:
STL ka `next_permutation` bhi same algorithm use karta hai:
- Yeh dip point (arr[i] < arr[i+1]) find karta hai.
- Smallest element jo arr[i] se bada hai, uske saath swap karta hai.
- Baaki right portion ko reverse karta hai.
- Agar dip point nahi mila, toh pura array reverse karta hai.
Yeh in-place hota hai aur O(n) time mein kaam karta hai.
*/
vector<int> nextPermutationOptimal(vector<int>& arr) {
    int n = arr.size();
    int i = n - 2;

    // Step 1: Find dip point (i where arr[i] < arr[i+1])
    while(i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    // Step 2: If dip point found, find j where arr[j] > arr[i]
    if(i >= 0) {
        int j = n - 1;
        while(j >= 0 && arr[j] <= arr[i]) {
            j--;
        }
        // Step 3: Swap arr[i] and arr[j]
        swap(arr[i], arr[j]);
    }

    // Step 4: Reverse from i+1 to end
    int left = i + 1, right = n - 1;
    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    return arr;
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {3, 2, 1};
    vector<int> arr3 = {1, 1, 5};
    vector<int> arr1_copy = arr1, arr2_copy = arr2, arr3_copy = arr3;

    cout << "Input: arr = [1, 2, 3]" << endl;
    cout << "Brute Force: ";
    vector<int> result1 = nextPermutationBrute(arr1);
    for(int x : result1) cout << x << " ";
    cout << endl;
    cout << "Better (STL): ";
    vector<int> result2 = nextPermutationBetter(arr1_copy);
    for(int x : result2) cout << x << " ";
    cout << endl;
    cout << "Optimal: ";
    vector<int> result3 = nextPermutationOptimal(arr1_copy);
    for(int x : result3) cout << x << " ";
    cout << endl;

    cout << "\nInput: arr = [3, 2, 1]" << endl;
    cout << "Brute Force: ";
    result1 = nextPermutationBrute(arr2);
    for(int x : result1) cout << x << " ";
    cout << endl;
    cout << "Better (STL): ";
    result2 = nextPermutationBetter(arr2_copy);
    for(int x : result2) cout << x << " ";
    cout << endl;
    cout << "Optimal: ";
    result3 = nextPermutationOptimal(arr2_copy);
    for(int x : result3) cout << x << " ";
    cout << endl;

    cout << "\nInput: arr = [1, 1, 5]" << endl;
    cout << "Brute Force: ";
    result1 = nextPermutationBrute(arr3);
    for(int x : result1) cout << x << " ";
    cout << endl;
    cout << "Better (STL): ";
    result2 = nextPermutationBetter(arr3_copy);
    for(int x : result2) cout << x << " ";
    cout << endl;
    cout << "Optimal: ";
    result3 = nextPermutationOptimal(arr3_copy);
    for(int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}
