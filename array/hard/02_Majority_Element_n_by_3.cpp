/*
💡 Problem: Majority Element (> N/3)

🧠 Task:
Ek array diya hai. Wo elements dhoondho jo N/3 se zyada baar aate hain.
Output mein un elements ka vector return karo.

🧪 Examples:
Input: nums = [3,2,3]
Output: [3] (3 appears 2 times, N/3 = 1)
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach: Count Each Element
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Har element ke liye poore array mein count karo ki wo kitni baar aata hai. Agar count > N/3 hai, toh us element ko result mein daalo.

📜 Algorithm:
1. Ek vector rakho result ke liye.
2. Har element ke liye:
   - Poore array mein uska count nikalo.
   - Agar count > N/3, toh result mein daalo.
3. Duplicate avoid karne ke liye, result ko sort karo aur unique elements rakho.
4. Result return karo.

📍 Intuition:
- Yeh seedha tareeka hai: har number ka count check karo.
- Lekin yeh slow hai kyunki har element ke liye poora array scan karna padta hai.

🕒 Time: O(n²) (nested loops)
💾 Space: O(1) (result vector ke alawa)
*/
vector<int> majorityElementBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(nums[j] == nums[i]) count++;
        }
        if(count > n/3) result.push_back(nums[i]);
    }
    
    // Remove duplicates
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    return result;
}

// -------------------------------------------------
// 🦁 Better Approach: Using Hash Map
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Ek hash map mein har element ka count store karo. Jo elements ka count > N/3 ho, unko result mein daalo.

📜 Algorithm:
1. Ek hash map rakho jo element aur uska count store kare.
2. Array ke har element ke liye:
   - Map mein count badhao.
3. Map ke har element ke liye:
   - Agar count > N/3, toh result mein daalo.
4. Result return karo.

📍 Intuition:
- Hash map se hum ek baar mein saare elements ka count nikal sakte hain.
- Yeh faster hai kyunki array ko baar-baar scan nahi karna padta.
- Space trade-off hai, lekin time complexity better hai.

🕒 Time: O(n) (single pass for map)
💾 Space: O(n) (hash map ke liye)
*/
vector<int> majorityElementBetter(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> countMap;
    vector<int> result;
    
    for(int num : nums) {
        countMap[num]++;
    }
    
    for(auto& pair : countMap) {
        if(pair.second > n/3) {
            result.push_back(pair.first);
        }
    }
    
    return result;
}

// -------------------------------------------------
// ⚡ Optimal Approach: Boyer-Moore Voting for N/3
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Boyer-Moore Voting Algorithm ko extend karke use karo. Since N/3 se zyada wale maximum 2 elements ho sakte hain, do candidates rakho aur unke counts track karo. Last mein confirm karo ki candidates ka count > N/3 hai.

📜 Algorithm:
1. Do candidates (c1, c2) aur unke counts (cnt1, cnt2) rakho.
2. Array ke har element ke liye:
   - Agar element c1 ya c2 hai, toh uska count badhao.
   - Nahi toh, kisi candidate ko replace karo ya dono counts ghatayo.
3. Counts reset karke candidates ka final count nikalo.
4. Jo candidates ka count > N/3 ho, unko result mein daalo.
5. Result return karo.

📍 Intuition:
- N/3 se zyada wale elements maximum 2 ho sakte hain, toh do candidates kaafi hain.
- Boyer-Moore majority voting ka idea extend kiya hai: jab koi element match nahi karta, dono candidates ke counts ghatate hain.
- Final check zaroori hai kyunki candidates galat bhi ho sakte hain.

🕒 Time: O(n) (do passes)
💾 Space: O(1) (koi extra space nahi)
*/
vector<int> majorityElementOptimal(vector<int>& nums) {
    int n = nums.size();
    int c1 = 0, c2 = 0; // Candidates
    int cnt1 = 0, cnt2 = 0; // Counts
    
    // First pass: Find potential candidates
    for(int num : nums) {
        if(num == c1) cnt1++;
        else if(num == c2) cnt2++;
        else if(cnt1 == 0) {
            c1 = num;
            cnt1 = 1;
        } else if(cnt2 == 0) {
            c2 = num;
            cnt2 = 1;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    
    // Second pass: Verify candidates
    cnt1 = 0, cnt2 = 0;
    for(int num : nums) {
        if(num == c1) cnt1++;
        else if(num == c2) cnt2++;
    }
    
    vector<int> result;
    if(cnt1 > n/3) result.push_back(c1);
    if(cnt2 > n/3) result.push_back(c2);
    
    return result;
}

// -------------------------------------------------
// 🔍 Driver Code (Compact)
// -------------------------------------------------
void printVector(const vector<int>& vec) {
    cout << "[";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums = {3,2,3};
    cout << "Input: nums = [3,2,3]" << endl;
    
    cout << "Brute Force: ";
    printVector(majorityElementBrute(nums));
    
    cout << "Better (Hash Map): ";
    printVector(majorityElementBetter(nums));
    
    cout << "Optimal (Boyer-Moore): ";
    printVector(majorityElementOptimal(nums));
    
    return 0;
}