/*
💡 Problem: Pascal's Triangle

🧠 Task:
1. Kisi specific position (r,c) ka number nikalna (0-based indexing).
2. Kisi row ke saare numbers print karna.
3. N rows tak poora Pascal's Triangle generate karna.

🧪 Examples:
Task 1: row=4, col=2 -> 6 ([1,4,6,4,1])
Task 2: row=4 -> [1,4,6,4,1]
Task 3: n=5 ->
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// ⚡ Task 1: Print Particular Number (r,c)
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Pascal's Triangle ka (r,c) element nCr (combination) hai. Hum nCr formula use karenge: nCr = n! / (r! * (n-r)!).
Lekin direct factorial slow hai, toh optimized formula use karte hain: nCr = (n * (n-1) * ... * (n-r+1)) / (1 * 2 * ... * r).

📜 Algorithm:
1. row=r aur col=c input lo.
2. nCr calculate karo: 
   - Numerator: r se col+1 tak multiply karo.
   - Denominator: 1 se col tak divide karo.
3. Result return karo.

📍 Intuition:
- Pascal's Triangle ka har element nCr hai (row choose col).
- Direct nCr formula se hum ek specific number jaldi nikal sakte hain.
- Division step-by-step karne se overflow kam hota hai.

🕒 Time: O(c) (col tak loop)
💾 Space: O(1) (koi extra space nahi)
*/
long long getElement(int r, int c) {
    long long result = 1;
    for(int i = 0; i < c; i++) {
        result *= (r - i);
        result /= (i + 1);
    }
    return result;
}

// -------------------------------------------------
// ⚡ Task 2: Print Specific Row
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Ek row ke saare elements nCr formula se nikal sakte hain. Har element ko previous element se calculate karo taaki baar-baar nCr na karna pade.

📜 Algorithm:
1. Row number r input lo.
2. Ek vector rakho aur pehla element 1 daalo.
3. Har agla element calculate karo: prev * (r-i) / (i+1).
4. Vector return karo.

📍 Intuition:
- Har row ka element nCr hai, aur nCr ko previous nC(r-1) se jaldi nikal sakte hain.
- Yeh approach ek row ke saare elements efficiently deta hai.

🕒 Time: O(r) (row ke size tak loop)
💾 Space: O(r) (output vector ke liye)
*/
vector<int> getRow(int r) {
    vector<int> row;
    long long val = 1;
    row.push_back(1); // First element is always 1
    
    for(int i = 0; i < r; i++) {
        val *= (r - i);
        val /= (i + 1);
        row.push_back(val);
    }
    
    return row;
}

// -------------------------------------------------
// ⚡ Task 3: Print Whole Triangle
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Poora triangle generate karne ke liye, har row ko previous row ke basis pe banao. Har element previous row ke do elements ka sum hota hai.

📜 Algorithm:
1. N input lo (number of rows).
2. Ek 2D vector rakho jisme har row store hogi.
3. Pehli row mein [1] daalo.
4. Har agli row ke liye:
   - Pehla aur last element 1.
   - Bich ke elements = prev_row[i-1] + prev_row[i].
5. 2D vector return karo.

📍 Intuition:
- Pascal's Triangle mein har row previous row se ban sakti hai.
- Har element previous row ke do adjacent elements ka sum hai.
- Yeh approach poora triangle efficiently banata hai.

🕒 Time: O(n²) (n rows, har row mein max n elements)
💾 Space: O(n²) (output triangle ke liye)
*/
vector<vector<int>> generateTriangle(int n) {
    vector<vector<int>> triangle;
    
    for(int i = 0; i < n; i++) {
        vector<int> row(i + 1, 1); // Initialize row with 1s
        for(int j = 1; j < i; j++) {
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
        triangle.push_back(row);
    }
    
    return triangle;
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

void printTriangle(const vector<vector<int>>& triangle) {
    for(const auto& row : triangle) {
        printVector(row);
    }
}

int main() {
    int r = 4, c = 2, n = 5;
    cout << "Task 1: Particular Number (row=" << r << ", col=" << c << "): ";
    cout << getElement(r, c) << endl;
    
    cout << "Task 2: Print Row (row=" << r << "): ";
    printVector(getRow(r));
    
    cout << "Task 3: Whole Triangle (n=" << n << "):" << endl;
    printTriangle(generateTriangle(n));
    
    return 0;
}