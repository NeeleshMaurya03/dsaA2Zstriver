/*
💡 Problem: Rotate Matrix by 90 Degrees

🧠 Task:
Ek n x n matrix diya hai. Isko 90 degrees clockwise rotate karo.
In-place karna hai jab possible ho.

🧪 Examples:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach: Using Another Matrix
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Ek naya matrix banao aur original matrix ke numbers ko 90 degrees clockwise ghuma ke naye matrix mein daalo. Fir naye matrix ko wapas original mein copy karo.

📜 Algorithm:
1. Ek n x n ka naya matrix (temp) banao.
2. Har cell (i,j) ko temp matrix mein (j, n-1-i) position pe daalo.
3. Temp matrix ke numbers ko original matrix mein copy karo.

📍 Intuition:
- 90 degrees clockwise ghumane se pehli row last column ban jati hai, doosri row second-last column, aur aise hi.
- (i,j) ka number (j, n-1-i) pe jata hai kyunki rows columns mein badal jati hain aur columns ulta ho jata hai.
- Yeh tareeka simple hai, lekin extra matrix space leta hai.

🕒 Time: O(n*n) (traverse aur copy)
💾 Space: O(n*n) (extra matrix)
*/
void rotateBrute(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> temp(n, vector<int>(n));

    // Step 1: Fill temp matrix with rotated positions
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[j][n-1-i] = matrix[i][j];
        }
    }

    // Step 2: Copy temp back to matrix
    matrix = temp;
}

// -------------------------------------------------
// ⚡ Optimal Approach: Transpose then Reverse
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Extra matrix ke bina, matrix ko in-place rotate karo. Pehle matrix ko transpose karo (rows ko columns se swap), fir har row ko reverse karo.

📜 Algorithm:
1. Matrix ko transpose karo: (i,j) ko (j,i) ke saath swap karo, sirf upper triangle ke liye.
2. Har row ko reverse karo (left to right).
3. Modified matrix return karo.

📍 Intuition:
- Transpose se rows aur columns swap ho jate hain, jo 90 degrees anticlockwise jaisa hota hai.
- Row reverse karne se numbers correct order mein aate hain, jo 90 degrees clockwise deta hai.
- Yeh in-place hai, toh space bachata hai.

🕒 Time: O(n*n) (transpose + reverse)
💾 Space: O(1) (in-place)
*/
void rotateOptimal(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose (swap elements across diagonal)
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// -------------------------------------------------
// 🔍 Driver Code (Compact)
// -------------------------------------------------
void printMatrix(vector<vector<int>>& matrix) {
    for(auto& row : matrix) {
        cout << "[";
        for(int i = 0; i < row.size(); i++) {
            cout << row[i];
            if(i < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Input: [[1,2,3],[4,5,6],[7,8,9]]" << endl;
    
    vector<vector<int>> copy = matrix;
    cout << "Brute Force:" << endl; rotateBrute(copy); printMatrix(copy);
    copy = matrix;
    cout << "Optimal:" << endl; rotateOptimal(copy); printMatrix(copy);
    
    return 0;
}