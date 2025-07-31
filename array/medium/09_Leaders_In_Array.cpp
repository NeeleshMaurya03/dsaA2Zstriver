/*
💡 Problem: Leaders in an Array

🧠 Task:
Ek array diya gaya hai. Leaders find karo.
Leader wo element hai jo apne right side ke sabhi elements se bada ya barabar ho.
Leaders ko right-to-left order mein print karo (original array ke order mein).

🧪 Example:
Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]

Input: arr = [1, 2, 3, 4, 0]
Output: [4, 0]

Input: arr = [7]
Output: [7]
*/

#include <iostream>
#include <vector>
#include <algorithm> // For reverse
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Nested Loops)
// -------------------------------------------------
/*
📘 Steps:
1. Har element ke liye check karo ki kya woh apne right side ke sabhi elements se bada ya barabar hai.
2. Agar hai, toh usko leaders vector mein daalo.
3. Leaders ko original order mein print karo.

🕒 Time: O(n²)
💾 Space: O(n) (leaders store karne ke liye)
*/
vector<int> findLeadersBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;

    for(int i = 0; i < n; i++) {
        bool isLeader = true;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                isLeader = false;
                break;
            }
        }
        if(isLeader) {
            leaders.push_back(arr[i]);
        }
    }

    return leaders;
}

// -------------------------------------------------
// ⚡ Optimal Approach (Right to Left Scan)
// -------------------------------------------------
/*
📘 Steps:
1. Rightmost element hamesha leader hota hai, kyunki uske right mein koi element nahi.
2. Right se left traverse karo:
   - Ek variable `maxSoFar` rakho jo right side ka maximum element track kare.
   - Agar current element `maxSoFar` se bada ya barabar hai, toh woh leader hai.
   - `maxSoFar` update karo agar current element bada ho.
3. Leaders ko vector mein store karo aur original order mein print karo.

🕒 Time: O(n)
💾 Space: O(n) (leaders store karne ke liye)
*/
vector<int> findLeadersOptimal(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    int maxSoFar = arr[n - 1]; // Rightmost element is always a leader
    leaders.push_back(maxSoFar);

    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] >= maxSoFar) {
            leaders.push_back(arr[i]);
            maxSoFar = arr[i];
        }
    }

    // Reverse leaders to maintain original order
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> arr1 = {16, 17, 4, 3, 5, 2};
    vector<int> arr2 = {1, 2, 3, 4, 0};
    vector<int> arr3 = {7};

    cout << "Input: arr = [16, 17, 4, 3, 5, 2]" << endl;
    cout << "Brute Force: ";
    vector<int> result1 = findLeadersBrute(arr1);
    for(int x : result1) cout << x << " ";
    cout << endl;
    cout << "Optimal (Right to Left): ";
    vector<int> result2 = findLeadersOptimal(arr1);
    for(int x : result2) cout << x << " ";
    cout << endl;

    cout << "\nInput: arr = [1, 2, 3, 4, 0]" << endl;
    cout << "Brute Force: ";
    result1 = findLeadersBrute(arr2);
    for(int x : result1) cout << x << " ";
    cout << endl;
    cout << "Optimal (Right to Left): ";
    result2 = findLeadersOptimal(arr2);
    for(int x : result2) cout << x << " ";
    cout << endl;

    cout << "\nInput: arr = [7]" << endl;
    cout << "Brute Force: ";
    result1 = findLeadersBrute(arr3);
    for(int x : result1) cout << x << " ";
    cout << endl;
    cout << "Optimal (Right to Left): ";
    result2 = findLeadersOptimal(arr3);
    for(int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}