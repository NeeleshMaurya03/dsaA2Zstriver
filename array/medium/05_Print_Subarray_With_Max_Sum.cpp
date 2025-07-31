/*
💡 Problem: Print Subarray with Maximum Sum

🧠 Task:
Ek array diya gaya hai jisme positive aur negative numbers hain.
Wo subarray dhoondo aur print karo jiska sum maximum ho.

🧪 Example:
Input: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: Subarray: [4, -1, 2, 1], Sum: 6

Input: arr = [1]
Output: Subarray: [1], Sum: 1

Input: arr = [-2, -1]
Output: Subarray: [-1], Sum: -1
*/

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Nested Loops)
// -------------------------------------------------
/*
📘 Steps:
1. Har possible subarray ke liye sum calculate karo.
2. Har subarray ka sum compare karo aur maximum sum rakho.
3. Max sum wale subarray ke start aur end indices store karo.
4. Subarray print karo.

🕒 Time: O(n²)
💾 Space: O(1)
*/
void printMaxSubArrayBrute(vector<int>& arr) {
    int n = arr.size();
    int maxSum = arr[0]; // Initial max sum (at least one element)
    int start = 0, end = 0;

    for(int i = 0; i < n; i++) {
        int currSum = 0;
        for(int j = i; j < n; j++) {
            currSum += arr[j]; // Current subarray ka sum
            if(currSum > maxSum) {
                maxSum = currSum;
                start = i;
                end = j;
            }
        }
    }

    // Print subarray and sum
    cout << "Subarray: [";
    for(int i = start; i <= end; i++) {
        cout << arr[i];
        if(i < end) cout << ", ";
    }
    cout << "], Sum: " << maxSum << endl;
}

// -------------------------------------------------
// ⚡ Optimal Approach (Kadane’s Algorithm with Tracking)
// -------------------------------------------------
/*
📘 Steps:
1. Ek variable `currSum` rakho jo current subarray ka sum track kare.
2. Ek variable `maxSum` rakho jo maximum sum store kare.
3. Start aur end indices track karo max sum wale subarray ke.
4. Har element ke liye:
   - `currSum = max(arr[i], currSum + arr[i])` (naya subarray ya continue).
   - Agar `currSum` bada ho, toh `maxSum` aur indices update karo.
   - Agar `currSum < 0`, toh `currSum = 0` aur naya start index set karo.
5. Subarray print karo using stored indices.

🕒 Time: O(n)
💾 Space: O(1)
*/
void printMaxSubArrayOptimal(vector<int>& arr) {
    int n = arr.size();
    int maxSum = arr[0]; // Initial max sum (at least one element)
    int currSum = 0;
    int start = 0, end = 0, tempStart = 0;

    for(int i = 0; i < n; i++) {
        if(currSum < 0) {
            currSum = 0; // Reset sum
            tempStart = i; // New potential start
        }
        currSum += arr[i]; // Add current element

        if(currSum > maxSum) {
            maxSum = currSum; // Update max sum
            start = tempStart; // Update start index
            end = i; // Update end index
        }
    }

    // Print subarray and sum
    cout << "Subarray: [";
    for(int i = start; i <= end; i++) {
        cout << arr[i];
        if(i < end) cout << ", ";
    }
    cout << "], Sum: " << maxSum << endl;
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> arr2 = {1};
    vector<int> arr3 = {-2, -1};

    cout << "Input: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]" << endl;
    cout << "Brute Force: ";
    printMaxSubArrayBrute(arr1);
    cout << "Optimal (Kadane’s): ";
    printMaxSubArrayOptimal(arr1);

    cout << "\nInput: arr = [1]" << endl;
    cout << "Brute Force: ";
    printMaxSubArrayBrute(arr2);
    cout << "Optimal (Kadane’s): ";
    printMaxSubArrayOptimal(arr2);

    cout << "\nInput: arr = [-2, -1]" << endl;
    cout << "Brute Force: ";
    printMaxSubArrayBrute(arr3);
    cout << "Optimal (Kadane’s): ";
    printMaxSubArrayOptimal(arr3);

    return 0;
}