/*
💡 Problem: Set Matrix Zeroes

🧠 Task:
Ek m x n matrix diya hai. Agar koi element 0 hai, toh uski poori row aur column ko 0 kar do.
In-place karna hai.

🧪 Examples:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------
// 🐢 Brute Force Approach: Separate Marking
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Iska idea simple hai: matrix mein har 0 dhoondho, aur uski row aur column ke numbers ko -1 se mark karo (jo 0 na ho). Baad mein -1 ko 0 kar do. Yeh tab kaam karta hai jab matrix mein negative numbers na ho.

📜 Algorithm:
1. Matrix ke har cell ko check karo.
2. Agar koi cell (i,j) mein 0 hai, toh uski row i aur column j ke saare non-zero numbers ko -1 kar do.
3. Har 0 ke liye yeh karo.
4. Last mein, saare -1 ko 0 kar do.

📍 Intuition:
- Direct 0 se mark nahi kar sakte kyunki original 0s aur naye 0s mix ho jayenge, aur galat rows/columns 0 ho jayenge.
- Isliye -1 se mark karte hain taaki original 0s safe rahen.
- 0 wale cells ko chhodna zaroori hai warna original 0s kho jayenge.

🕒 Time: O(m*n) (matrix traverse karne ka)
💾 Space: O(k) (k = 0s ki sankhya, unke indices store karne ke liye)
*/
void markRow(vector<vector<int>>& matrix, int i, int n) {
    for(int j = 0; j < n; j++) {
        if(matrix[i][j] != 0) matrix[i][j] = -1;
    }
}

void markCol(vector<vector<int>>& matrix, int j, int m) {
    for(int i = 0; i < m; i++) {
        if(matrix[i][j] != 0) matrix[i][j] = -1;
    }
}

void setZeroesBrute(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> zeroes;

    // Step 1: Find all 0s
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                zeroes.push_back({i, j});
            }
        }
    }

    // Step 2: Mark rows and columns with -1
    for(int k = 0; k < zeroes.size(); k++) {
        int i = zeroes[k].first;
        int j = zeroes[k].second;
        markRow(matrix, i, n);
        markCol(matrix, j, m);
    }

    // Step 3: Convert -1 to 0
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == -1) matrix[i][j] = 0;
        }
    }
}

// -------------------------------------------------
// 🦁 Better Approach: Extra Space for Row/Column Marking
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Isme hum matrix ke andar direct mark nahi karte. Do alag arrays banate hain: ek rows ke liye, ek columns ke liye. 0 milne par us row aur column ko array mein mark karte hain, aur baad mein un rows/columns ko 0 kar dete hain.

📜 Algorithm:
1. Do arrays banaye: row (size m) aur col (size n), dono ko 0 se start karo.
2. Matrix ke har cell ko check karo.
3. Agar cell (i,j) mein 0 hai, toh row[i] aur col[j] ko 1 kar do.
4. Har 0 ke liye yeh karo.
5. Matrix dobara check karo, aur agar row[i] ya col[j] 1 hai, toh cell (i,j) ko 0 kar do.

📍 Intuition:
- Arrays ka use karke hum -1 wali problem se bach jaate hain.
- Pehle saare 0s ke liye mark karte hain, fir ek baar mein zeroes set karte hain.
- Yeh safe hai kyunki matrix ke original values disturb nahi hote marking ke time.

🕒 Time: O(m*n) (matrix traverse karne ka)
💾 Space: O(m + n) (row aur col arrays ke liye)
*/
void setZeroesBetter(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m, 0); // To mark rows
    vector<int> col(n, 0); // To mark columns

    // Step 1: Mark rows and columns containing 0
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Step 2: Set zeroes for marked rows and columns
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

// -------------------------------------------------
// ⚡ Optimal Approach: Using First Row/Column for Marking
// -------------------------------------------------
/*
📘 Algorithm / Intuition:
Isme hum extra arrays nahi banate. Matrix ke first row aur first column ko hi marking ke liye use karte hain. Problem yeh hai ki first cell (0,0) dono row aur column ke liye common hai, toh ek alag variable col0 banate hain.

📜 Algorithm:
1. Ek variable col0 = true rakho aur check karo ki first row ya column mein 0 hai.
2. Matrix ke har cell ko check karo:
   - Agar cell (i,j) mein 0 hai, toh matrix[i][0] aur matrix[0][j] ko 0 kar do.
   - Agar j=0 hai, toh col0 = false kar do (matrix[0][0] ko dobara nahi chhedna).
3. Cells (1,1) se (m-1,n-1) tak check karo aur matrix[i][0] ya matrix[0][j] ke basis pe 0 set karo.
4. Last mein first row aur column ko set karo:
   - Agar first row mein 0 tha, toh poori first row ko 0 kar do.
   - Agar col0 = false, toh first column ko 0 kar do.

📍 Intuition:
- First row aur column ko marker banakar space bachate hain.
- col0 variable matrix[0][0] ke overlap ko handle karta hai.
- Pehle (1,1) se (m-1,n-1) set karna zaroori hai kyunki first row/column ke values baki matrix ke liye important hain.
- First row pehle set karte hain kyunki column ka modification matrix[0][0] pe depend karta hai.

🕒 Time: O(m*n) (matrix traverse karne ka)
💾 Space: O(1) (no extra space, matrix ke first row/column use hote hain)
*/
void setZeroesOptimal(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowZero = false, col0 = true;

    // Step 1: Check if first row has any 0
    for(int j = 0; j < n; j++) {
        if(matrix[0][j] == 0) firstRowZero = true;
    }

    // Step 2: Check if first column has any 0
    for(int i = 0; i < m; i++) {
        if(matrix[i][0] == 0) col0 = false;
    }

    // Step 3: Use first row and column to mark zeroes
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark first cell of row
                matrix[0][j] = 0; // Mark first cell of column
            }
        }
    }

    // Step 4: Set zeroes based on marks in first row and column
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 5: Set first row to 0 if needed
    if(firstRowZero) {
        for(int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 6: Set first column to 0 if needed
    if(!col0) {
        for(int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
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
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    cout << "Input: [[1,1,1],[1,0,1],[1,1,1]]" << endl;
    
    vector<vector<int>> copy = matrix;
    cout << "Brute Force:" << endl; setZeroesBrute(copy); printMatrix(copy);
    copy = matrix;
    cout << "Better:" << endl; setZeroesBetter(copy); printMatrix(copy);
    copy = matrix;
    cout << "Optimal:" << endl; setZeroesOptimal(copy); printMatrix(copy);
    
    return 0;
}