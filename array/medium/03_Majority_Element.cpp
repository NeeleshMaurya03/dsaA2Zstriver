/*
💡 Problem: Majority Element

🧠 Task:
Ek array diya gaya hai jisme ek element aisa hai jo n/2 se zyada baar aata hai (n = array size).
Woh element dhoondo.

🧪 Example:
Input: arr = [2, 2, 1, 1, 1, 2, 2]
Output: 2 (kyunki 2 appears 4 times, jo n/2 = 7/2 = 3 se zyada hai)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Nested Loops)
// -------------------------------------------------
/*
📘 Steps:
1. Har element ke liye count karo kitni baar aata hai.
2. Agar kisi element ka count > n/2 ho jaye, wahi majority element hai.

🕒 Time: O(n²)
💾 Space: O(1)
*/
int majorityElementBrute(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] == arr[i]) {
                count++;
            }
            if(count > n/2) {
                return arr[i];
            }
        }
    }
    return -1; // Agar majority element nahi mila (should not happen per problem)
}

// -------------------------------------------------
// 💼 Better Approach (Hashing using Map)
// -------------------------------------------------
/*
📘 Steps:
1. Ek map banao jisme har element ka count store ho.
2. Har element ka count check karo, agar > n/2 ho toh return karo.

🕒 Time: O(n)
💾 Space: O(n)
*/
int majorityElementHashing(vector<int>& arr) {
    unordered_map<int, int> mp; // element -> count
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
        if(mp[arr[i]] > n/2) {
            return arr[i];
        }
    }
    return -1; // Agar majority element nahi mila (should not happen per problem)
}

// -------------------------------------------------
// ⚡ Optimal Approach (Boyer-Moore Voting Algorithm with Verification)
// -------------------------------------------------
/*
📘 Steps:
1. Ek candidate choose karo aur uska count rakho.
2. Agar same element mila, count++ karo.
3. Agar alag element mila, count-- karo.
4. Agar count == 0 ho jaye, naya candidate choose karo.
5. Last mein jo candidate bachta hai, usko verify karo:
   - Ek extra pass mein candidate ka count check karo ki > n/2 hai ya nahi.

⚠️ Note: Verification ensures candidate sahi majority element hai.

🕒 Time: O(n) (single pass + verification pass)
💾 Space: O(1)
*/
int majorityElementVoting(vector<int>& arr) {
    int n = arr.size();
    int count = 0, candidate = 0;

    // Step 1: Find candidate
    for(int num : arr) {
        if(count == 0) {
            candidate = num;
        }
        if(num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Verify candidate
    count = 0;
    for(int num : arr) {
        if(num == candidate) {
            count++;
        }
    }
    if(count > n/2) {
        return candidate;
    }
    return -1; // Agar majority element nahi mila
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    cout << "Input: arr = [2, 2, 1, 1, 1, 2, 2]" << endl;
    cout << "Brute Force (Nested Loops): " << majorityElementBrute(arr) << endl;
    cout << "Better (Hashing): " << majorityElementHashing(arr) << endl;
    cout << "Optimal (Voting Algorithm with Verification): " << majorityElementVoting(arr) << endl;

    return 0;
}