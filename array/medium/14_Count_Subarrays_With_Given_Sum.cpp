/*
💡 Problem: Subarray with Sum K

🧠 Task:
Ek array diya hai aur ek integer K. Subarray dhoondho jiska sum exactly K ho.
Output mein subarrays ka count return karo.

🧪 Examples:
Input: nums = [1,1,1], k = 2
Output: 2 (Subarrays: [1,1] at indices [0,1] and [1,2])
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach: Check All Subarrays
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Har possible subarray check karo aur uska sum calculate karo. Agar sum K ke barabar hai, toh count badhao.

📜 Algorithm:
1. Do nested loops se har subarray generate karo.
2. Har subarray ka sum calculate karo.
3. Agar sum == K, toh count++ karo.
4. Last mein count return karo.

📍 Intuition:
- Yeh simple hai: har starting point se har ending point tak subarray banao aur check karo.
- Kaam toh karta hai, lekin bahut slow hai kyunki har combination check karni padti hai.

🕒 Time: O(n²) (nested loops)
💾 Space: O(1) (koi extra space nahi)
*/
int subarraySumBrute(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j];
            if(sum == k) count++;
        }
    }
    
    return count;
}

// -------------------------------------------------
// 🦁 Better Approach: Sliding Window (Only Positive Numbers)
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Agar array mein sirf positive numbers hain, toh sliding window use karo. Ek window rakho jo sum track karta hai, aur jab sum K ke barabar ya bada ho, window ko adjust karo.

📜 Algorithm:
1. Do pointers rakho: start aur end, aur ek sum variable.
2. End pointer aage badhao aur sum mein nums[end] add karo.
3. Jab sum >= K:
   - Agar sum == K, count++ karo.
   - Sum se nums[start] subtract karo aur start++ karo.
4. Jab tak end < n, repeat karo.
5. Count return karo.

📍 Intuition:
- Positive numbers ke liye sliding window kaam karta hai kyunki sum bada hone par window chhota kar sakte hain.
- Yeh faster hai kyunki har element ko baar-baar nahi dekhna padta.

🕒 Time: O(n) (har element max do baar visit hota hai)
💾 Space: O(1) (koi extra space nahi)
*/
int subarraySumBetter(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0, sum = 0;
    int start = 0;
    
    for(int end = 0; end < n; end++) {
        sum += nums[end];
        
        while(sum > k && start <= end) {
            sum -= nums[start];
            start++;
        }
        
        if(sum == k) count++;
    }
    
    return count;
}

// -------------------------------------------------
// ⚡ Optimal Approach: Using Prefix Sum with Hash Map
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Prefix sum aur hash map use karke subarrays ka sum track karo. Har prefix sum ke liye check karo ki koi previous prefix sum aisa hai jiska difference K ho.

📜 Algorithm:
1. Ek hash map rakho jo prefix sum aur uski frequency store kare.
2. Ek sum variable rakho aur map mein sum=0 ke liye frequency=1 daal do.
3. Har element ke liye:
   - Sum mein current element add karo.
   - Agar (sum - k) map mein hai, toh count += map[sum - k].
   - Map mein current sum ki frequency badhao.
4. Count return karo.

📍 Intuition:
- Prefix sum se hum kisi bhi subarray ka sum jaldi nikal sakte hain.
- Agar sum - k map mein hai, toh ek subarray mila jiska sum K hai.
- Yeh negative numbers ke saath bhi kaam karta hai aur sabse efficient hai.

🕒 Time: O(n) (single pass with hash map)
💾 Space: O(n) (hash map ke liye)
*/
int subarraySumOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<long long, int> prefixSum;
    long long sum = 0;
    int count = 0;
    
    prefixSum[0] = 1; // For subarrays starting from index 0
    
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if(prefixSum.find(sum - k) != prefixSum.end()) {
            count += prefixSum[sum - k];
        }
        prefixSum[sum]++;
    }
    
    return count;
}

// -------------------------------------------------
// 🔍 Driver Code (Compact)
// -------------------------------------------------
int main() {
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << "Input: nums = [1,1,1], k = 2" << endl;
    
    cout << "Brute Force: " << subarraySumBrute(nums, k) << endl;
    cout << "Better (Positive Only): " << subarraySumBetter(nums, k) << endl;
    cout << "Optimal: " << subarraySumOptimal(nums, k) << endl;
    
    return 0;
}