/*
💡 Problem: Print Matrix in Spiral Order

🧠 Task:
Ek m x n matrix diya hai. Isko spiral order mein print karo (top-left se shuru, clockwise: right → down → left → up).

🧪 Examples:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// ⚡ Optimal Approach: Boundary Traversal
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Matrix ke boundaries ko traverse karo (top, right, bottom, left) aur andar ki taraf shrink karte jao. Ek vector mein elements store karo spiral order mein.

📜 Algorithm:
1. Char pointers rakho: top, bottom, left, right boundaries ke liye.
2. Ek result vector banao.
3. Jab tak top <= bottom aur left <= right:
   - Top row ko left se right tak print karo, top++.
   - Right column ko top se bottom tak print karo, right--.
   - Agar top <= bottom, bottom row ko right se left tak print karo, bottom--.
   - Agar left <= right, left column ko bottom se top tak print karo, left++.
4. Result vector return karo.

📍 Intuition:
- Matrix ke bahar se andar tak spiral order mein jana hai.
- Boundaries ko track karke hum ek-ek layer print karte hain.
- Har direction ke baad boundary shrink karte hain taaki repeat na ho.

🕒 Time: O(m*n) (har element ek baar visit hota hai)
💾 Space: O(1) (output vector ke alawa koi extra space nahi)
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> result;
    
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    
    while(top <= bottom && left <= right) {
        // Print top row (left to right)
        for(int j = left; j <= right; j++) {
            result.push_back(matrix[top][j]);
        }
        top++;
        
        // Print right column (top to bottom)
        for(int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        
        // Print bottom row (right to left)
        if(top <= bottom) {
            for(int j = right; j >= left; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
        }
        
        // Print left column (bottom to top)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    
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
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Input: [[1,2,3],[4,5,6],[7,8,9]]" << endl;
    
    cout << "Spiral Order:" << endl;
    vector<int> result = spiralOrder(matrix);
    printVector(result);
    
    return 0;
}