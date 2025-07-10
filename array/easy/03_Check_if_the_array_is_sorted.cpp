/*
💡 Problem: Check if the Array is Sorted

🧠 Task:
Ek array diya gaya hai. Check karo ki kya voh strictly/increasing order mein sorted hai ya nahi.
Increasing order ka matlab:
👉 har element apne next element se chhota ya barabar hona chahiye → arr[i] <= arr[i+1]
Jaise:
✅ [1, 2, 3, 4, 5] → YES
❌ [1, 3, 2, 4]    → NO
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 🔸 Input array
    vector<int> arr = {1, 2, 3, 4, 5}; // Try with {1, 3, 2, 4} to test "Not Sorted"

    // 🔥 Optimal Approach:
    // ➤ Ek hi loop mein check karte hain
    // ➤ Har index i pe, agar arr[i] > arr[i+1] mil gaya toh sorted nahi hai
    // ➤ Jaise hi aisa case mile → break kar do
    //
    // Example: [1, 2, 3, 4, 5]
    // Check: 1<2 ✅, 2<3 ✅, 3<4 ✅, 4<5 ✅ → Sorted
    //
    // 🕒 Time: O(n)
    // 💾 Space: O(1)

    bool isSorted = true;

    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }

    if (isSorted)
        cout << "Optimal > Is Sorted? Yes" << endl;
    else
        cout << "Optimal > Is Sorted? No" << endl;

    return 0;
}
