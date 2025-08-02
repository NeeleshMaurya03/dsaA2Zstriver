/*
💡 Problem: Longest Consecutive Sequence

🧠 Task:
Ek array diya gaya hai jisme distinct integers hain.
Longest consecutive sequence ka length find karo (numbers jo ek doosre se 1 ka difference rakhte hain).

🧪 Example:
Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4 (Sequence: [1, 2, 3, 4])
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach: Nested Loops with Linear Search Function
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Ek straightforward approach hai har element ke liye consecutive sequence check karna. Har element x ke liye, hum linear search se x+1, x+2, x+3, aage ke numbers dhoondte hain. Har sequence ka length count karte hain aur maximum length store karte hain.

📜 Algorithm:
1. Ek loop se har element ko iterate karo.
2. Har element x ke liye, linearSearch function se x+1, x+2, aage ke numbers dhoondo.
3. Jab tak consecutive element milta hai:
   - x ko increment karo (x+1).
   - Current sequence ka length (cnt) increment karo.
4. Agar consecutive element nahi milta, loop break karo aur current sequence ka length store karo.
5. Sab sequences ke lengths mein se maximum length return karo.

🕒 Time: O(n²) (har element ke liye linear search)
💾 Space: O(1) (no extra space)
*/
bool linearSearch(vector<int>& a, int num) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        if(a[i] == num) return true;
    }
    return false;
}

int longestConsecutiveBrute(vector<int>& a) {
    int n = a.size();
    int longest = 0; // Handle empty array
    for(int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        while(linearSearch(a, x + 1)) {
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// -------------------------------------------------
// 🦁 Better Approach: Using Sort
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Array ko sort karke consecutive sequences check karna easier hai. Sorted array mein consecutive numbers ek doosre ke paas hote hain, toh hum loop se unko count kar sakte hain.

📜 Algorithm:
1. Array ko sort karo.
2. Teen variables rakho:
   - lastSmaller (current sequence ka last element).
   - cnt (current sequence ka length).
   - longest (maximum length).
3. Initialize lastSmaller = INT_MIN, cnt = 0, longest = 1.
4. Har element ke liye:
   - Agar arr[i] == lastSmaller + 1: Sequence continue karo, cnt++ aur lastSmaller update karo.
   - Agar arr[i] == lastSmaller: Skip karo (duplicate).
   - Agar arr[i] > lastSmaller + 1: Naya sequence start karo, cnt = 1, lastSmaller = arr[i].
5. Har iteration mein longest = max(longest, cnt) update karo.
6. longest return karo.

🕒 Time: O(n log n) (sorting ke liye)
💾 Space: O(1) (in-place sorting)
*/
int longestConsecutiveBetter(vector<int>& nums) {
    if(nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int maxLen = 1, currLen = 1;
    int lastSmaller = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == lastSmaller) continue; // Skip duplicates
        if(nums[i] == lastSmaller + 1) currLen++; // Continue sequence
        else currLen = 1; // Start new sequence
        lastSmaller = nums[i];
        maxLen = max(maxLen, currLen);
    }
    return maxLen;
}

// -------------------------------------------------
// ⚡ Optimal Approach: Using Unordered Set
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Brute force ko optimize karne ke liye unordered_set ka use karte hain taaki O(1) lookup ho. Sirf un numbers ke liye sequence check karte hain jo sequence ka starting point ho sakte hain (i.e., num-1 set mein nahi hai).

📜 Algorithm:
1. Saare elements ko unordered_set mein daalo.
2. Do variables rakho:
   - cnt (current sequence ka length).
   - longest (maximum length).
3. Har element x ke liye:
   - Agar x-1 set mein nahi hai, toh x sequence ka start hai.
   - Set se x+1, x+2, aage ke numbers count karo jab tak milte hain.
   - Current sequence ka length (cnt) store karo.
4. longest = max(longest, cnt) update karo.
5. longest return karo.

🕒 Time: O(n) (average case, unordered_set ke operations O(1))
💾 Space: O(n) (unordered_set ke liye)
*/
int longestConsecutiveOptimal(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    for(int num : nums) {
        if(s.find(num - 1) == s.end()) { // Sequence ka start
            int currNum = num;
            int cnt = 1;
            while(s.find(currNum + 1) != s.end()) {
                currNum++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

// -------------------------------------------------
// 🔍 Driver Code 
// -------------------------------------------------
int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Input: [100, 4, 200, 1, 3, 2]" << endl;
    
    vector<int> copy = nums;
    cout << "Brute Force: " << longestConsecutiveBrute(copy) << endl;
    copy = nums;
    cout << "Better (Sort): " << longestConsecutiveBetter(copy) << endl;
    copy = nums;
    cout << "Optimal (Unordered Set): " << longestConsecutiveOptimal(copy) << endl;
    
    return 0;
}