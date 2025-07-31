/*
💡 Problem: Two Sum (Three Approaches)

🧠 Task:
Ek array diya gaya hai aur ek target sum.
Check karo kya koi do elements aise hain jinka sum target ke equal ho.

🎯 Varieties:
1️⃣ Variety 1: "Yes" ya "No" return karo (pair exist karta hai ya nahi).
2️⃣ Variety 2: Indices return karo jinpe sum target ke barabar hai.

🧪 Example:
Input: nums = [2, 5, 6, 8, 11], target = 14
Output:
- Variety 1: Yes (6 + 8 = 14)
- Variety 2: [2, 3] (nums[2] + nums[3] = 14)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Nested Loops)
// -------------------------------------------------
/*
📘 Steps:
1. Har ek number ko baaki sab numbers ke saath jodo.
2. Agar koi pair ka sum target ke barabar milta hai, toh indices print karo.
3. Nahi toh "No" bolo.

🕒 Time: O(n²)
💾 Space: O(1)
*/
void twoSumBrute(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                cout << "Yes (Brute) → Indices: [" << i << ", " << j << "]" << endl;
                return;
            }
        }
    }
    cout << "No (Brute)" << endl;
}

// -------------------------------------------------
// 💼 Better Approach (Hashing using Map)
// -------------------------------------------------
/*
📘 Steps:
1. Ek map banao jisme number aur uska index store ho.
2. Har number ke liye check karo: (target - nums[i]) map mein hai ya nahi.
3. Agar hai, toh indices print karo.
4. Nahi toh current number map mein daalo.

🕒 Time: O(n)
💾 Space: O(n)
*/
void twoSumHashing(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // number -> index
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(mp.find(complement) != mp.end()) {
            cout << "Yes (Hashing) → Indices: [" << mp[complement] << ", " << i << "]" << endl;
            return;
        }
        mp[nums[i]] = i;
    }
    cout << "No (Hashing)" << endl;
}

// -------------------------------------------------
// ⚡ Optimal Approach (Two Pointer for Sorted Array)
// -------------------------------------------------
/*
📘 Steps:
1. Array ko sort karo.
2. Do pointers rakho: left (start) aur right (end).
3. Sum check karo:
   - Agar sum == target, pair mil gaya, "Yes" bolo.
   - Agar sum < target, left badhao.
   - Agar sum > target, right ghatao.

⚠️ Note: Yeh indices nahi deta directly (sorting ke baad indices lost ho jate hain).

🕒 Time: O(n log n)
💾 Space: O(1)
*/
void twoSumTwoPointer(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        int sum = nums[left] + nums[right];
        if(sum == target) {
            cout << "Yes (Two Pointer)" << endl;
            return;
        }
        else if(sum < target) left++;
        else right--;
    }
    cout << "No (Two Pointer)" << endl;
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> nums = {2, 5, 6, 8, 11};
    int target = 14;

    cout << "Input: nums = [2, 5, 6, 8, 11], target = 14" << endl;
    cout << "Brute Force: ";
    twoSumBrute(nums, target);
    cout << "Better (Hashing): ";
    twoSumHashing(nums, target);
    cout << "Optimal (Two Pointer): ";
    twoSumTwoPointer(nums, target);

    return 0;
}