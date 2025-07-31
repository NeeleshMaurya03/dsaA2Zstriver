/*
💡 Problem: Maximum Subarray Sum

🧠 Task:
Ek array diya gaya hai jisme positive aur negative numbers hain.
Wo subarray dhoondo jiska sum maximum ho.

🧪 Example:
Input: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6 (subarray: [4, -1, 2, 1])
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
3. Subarray ke start aur end indices bhi track kar sakte ho (optional).

🕒 Time: O(n²)
💾 Space: O(1)
*/
int maxSubArrayBrute(vector<int>& nums) {
    int n = nums.size();
    int maxSum = nums[0]; // Initial max sum (at least one element)

    for(int i = 0; i < n; i++) {
        int currSum = 0;
        for(int j = i; j < n; j++) {
            currSum += nums[j]; // Current subarray ka sum
            maxSum = max(maxSum, currSum); // Max sum update karo
        }
    }
    return maxSum;
}

// -------------------------------------------------
// ⚡ Optimal Approach (Kadane’s Algorithm)
// -------------------------------------------------
/*
📘 Steps:
1. Ek variable `sum` rakho jo current subarray ka sum track kare.
2. Ek variable `maxi` rakho jo maximum sum store kare.
3. Har element ke liye:
   - Current element ko `sum` mein add karo.
   - `maxi` ko update karo agar `sum` bada ho.
   - Agar `sum` negative ho jaye, toh `sum = 0` karke naya subarray shuru karo.
⚠️ Note: `sum = 0` karta hai kyunki negative sum aage ke subarrays ka sum chhota kar sakta hai.
😕 Toh better hai ki isko chhod do kyunki naya subarray shuru karna zyada faydemand ho sakta hai. Kadane’s Algorithm ka goal hai maximum sum wala subarray dhoondna, aur negative sum wala subarray rarely hi max sum deta hai.

🕒 Time: O(n)
💾 Space: O(1)
*/
int maxSubArrayKadane(vector<int>& nums) {
    int sum = 0;
    int maxi = nums[0]; // Initial max sum (at least one element)

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i]; // Current element add karo
        maxi = max(sum, maxi); // Max sum update karo
        if(sum < 0) {
            sum = 0; // Negative sum ko reset karo
        }
    }
    return maxi;
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]" << endl;
    cout << "Brute Force (Nested Loops): " << maxSubArrayBrute(nums) << endl;
    cout << "Optimal (Kadane’s Algorithm): " << maxSubArrayKadane(nums) << endl;

    return 0;
}