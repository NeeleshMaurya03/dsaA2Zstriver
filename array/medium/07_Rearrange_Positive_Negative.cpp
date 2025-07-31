/*
💡 Problem: Rearrange Array Elements by Sign

🧠 Task:
Ek array diya gaya hai jisme positive aur negative numbers hain.
Inko rearrange karo taaki positive aur negative numbers alternate ho.

🎯 Varieties:
1️⃣ Variety 1: Positive aur negative numbers ki count equal hai (pos == neg).
   Output mein alternate order: [pos, neg, pos, neg, ...]
2️⃣ Variety 2: Positive aur negative numbers ki count equal nahi bhi ho sakti (pos != neg).
   Output mein alternate order jab tak possible ho, baaki elements end mein.

🧪 Example:
Variety 1:
Input: arr = [3, -2, 1, -5, 2, -4]
Output: [3, -2, 1, -5, 2, -4] (alternate: pos, neg, pos, neg, ...)

Variety 2:
Input: arr = [3, -2, 1, -5, 2]
Output: [3, -2, 1, -5, 2] (alternate jab tak possible, baaki pos end mein)
*/

#include <iostream>
#include <vector>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach (Variety 1: pos == neg)
// -------------------------------------------------
/*
📘 Steps:
1. Do alag vectors banao: ek positive ke liye, ek negative ke liye.
2. Array ko traverse karke positive aur negative numbers alag karo.
3. Original array mein alternate order mein daalo: pos[0], neg[0], pos[1], neg[1], ...
⚠️ Note: Loop `arr.size()/2` tak chalta hai kyunki pos aur neg ki count n/2 hai, aur har iteration mein 2 positions (ek pos, ek neg) fill hoti hain.

🕒 Time: O(n)
💾 Space: O(n) (do extra vectors ke liye)
*/
vector<int> rearrangeArrayBrute(vector<int>& arr) {
    vector<int> neg;
    vector<int> pos;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    for(int i = 0; i < arr.size()/2; i++) {
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
    return arr;
}

// -------------------------------------------------
// ⚡ Optimal Approach (Variety 1: pos == neg)
// -------------------------------------------------
/*
📘 Steps:
1. Ek naya array `ans` banao size n ke.
2. Do pointers rakho: `pos = 0` (even indices), `neg = 1` (odd indices).
3. Array ko traverse karke:
   - Agar positive number hai, toh `ans[pos]` mein daalo, `pos += 2`.
   - Agar negative number hai, toh `ans[neg]` mein daalo, `neg += 2`.

🕒 Time: O(n)
💾 Space: O(n) (naya array ke liye)
*/
vector<int> rearrangeArrayOptimalV1(vector<int>& arr) {
    vector<int> ans(arr.size(), 0);
    int pos = 0;
    int neg = 1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] >= 0) {
            ans[pos] = arr[i];
            pos += 2;
        } else {
            ans[neg] = arr[i];
            neg += 2;
        }
    }
    return ans;
}

// -------------------------------------------------
// ⚡ Optimal Approach (Variety 2: pos != neg)
// -------------------------------------------------
/*
📘 Steps:
1. Do alag vectors banao: ek positive ke liye, ek negative ke liye.
2. Array ko traverse karke positive aur negative numbers alag karo.
3. Agar pos > neg:
   - Pehle alternate order mein daalo (pos, neg, pos, neg, ...) jab tak neg hai.
   - Baaki positive numbers end mein daalo.
4. Agar neg > pos:
   - Pehle alternate order mein daalo (pos, neg, pos, neg, ...) jab tak pos hai.
   - Baaki negative numbers end mein daalo.
⚠️ Note: Loop `min(p, n)` tak chalta hai taaki out-of-bounds na ho. Example mein jab i=1 aur n=2, arr[3] = neg[1] set hota hai, jo valid hai kyunki arr.size()=5 aur alternate order maintain hota hai.

🕒 Time: O(n)
💾 Space: O(n) (do extra vectors ke liye)
*/
vector<int> rearrangeArrayOptimalV2(vector<int>& arr) {
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < 0) {
            neg.push_back(arr[i]);
        } else {
            pos.push_back(arr[i]);
        }
    }
    int p = pos.size(), n = neg.size();
    if(p > n) {
        for(int i = 0; i < n; i++) {
            arr[i*2] = pos[i];
            arr[i*2+1] = neg[i];
        }
        int ind = n*2;
        for(int i = n; i < p; i++) {
            arr[ind++] = pos[i];
        }
    } else {
        for(int i = 0; i < p; i++) {
            arr[i*2] = pos[i];
            arr[i*2+1] = neg[i];
        }
        int ind = p*2;
        for(int i = p; i < n; i++) {
            arr[ind++] = neg[i];
        }
    }
    return arr;
}

// -------------------------------------------------
// 🔍 Driver Code
// -------------------------------------------------
int main() {
    vector<int> arr1 = {3, -2, 1, -5, 2, -4}; // Variety 1: pos == neg
    vector<int> arr2 = {3, -2, 1, -5, 2};     // Variety 2: pos != neg
    vector<int> arr1_copy = arr1, arr2_copy = arr2; // Copies for testing

    cout << "Variety 1 Input: arr = [3, -2, 1, -5, 2, -4] (pos == neg)" << endl;
    cout << "Brute Force (Variety 1): ";
    vector<int> result1 = rearrangeArrayBrute(arr1);
    for(int x : result1) cout << x << " ";
    cout << endl;

    cout << "Optimal (Variety 1): ";
    vector<int> result2 = rearrangeArrayOptimalV1(arr1_copy);
    for(int x : result2) cout << x << " ";
    cout << endl;

    cout << "\nVariety 2 Input: arr = [3, -2, 1, -5, 2] (pos != neg)" << endl;
    cout << "Optimal (Variety 2): ";
    vector<int> result3 = rearrangeArrayOptimalV2(arr2);
    for(int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}