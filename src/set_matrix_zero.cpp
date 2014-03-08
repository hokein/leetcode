#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// O(1) space method
// Reuse row[0] and col[0]
class Solution {
 public:
  void setZeroes(vector<vector<int> > &matrix) {
    bool has_column_zero = false;
    bool has_row_zero = false;
    for (int i = 0; i < matrix[0].size(); ++i)
      has_column_zero |= matrix[0][i] == 0;
    for (int j = 0; j < matrix.size(); ++j)
      has_row_zero |= matrix[j][0] == 0;
    
    for (int i = 1; i < matrix.size(); ++i)
      for (int j = 1; j < matrix[i].size(); ++j)
        if (matrix[i][j] == 0)
          matrix[i][0] = matrix[0][j] = 0;
    for (int i = 1; i < matrix.size(); ++i)
      for (int j = 1; j < matrix[i].size(); ++j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;
      }
    if (has_column_zero) {
      for (int i = 0; i < matrix[0].size(); ++i)
        matrix[0][i] = 0;
    }
    if (has_row_zero) {
      for (int j = 0; j < matrix.size(); ++j)
        matrix[j][0] = 0;
    }
  }
};

// O(n) stack space solution
// Divide and conquer
//
//  (lu_x, lu_y) .............
//               ....(i,j)....
//                 .   .    .
//                 .   .    .
//                 .   .    .
//               .............(rd_x, rd_y)
// matrix[i][j] == 0
// split to (i+1, lu_y, rd_x, rd_y) submatrix.
// then set row i, column j to zero.
class Solution2 {
 public:
  void setZeroes(vector<vector<int> > &matrix) {
    solve(0, 0, matrix.size()-1, matrix[0].size()-1, matrix);
  }
  void solve(int lu_x, int lu_y, int rd_x, int rd_y, vector<vector<int> > &matrix) {
    if (lu_x <= rd_x && lu_y <= rd_y) {
      for (int i = lu_x; i <= rd_x; ++i)
        for (int j = lu_y; j <= rd_y; ++j) {
          if (matrix[i][j] == 0) {
            solve(i+1, lu_y, rd_x, rd_y, matrix);
            zero_colum(j, 0, matrix.size()-1, matrix);
            // set the column k which matrix(i, k) = 0.
            for (int k = j+1; k < matrix[0].size(); ++k)
              if (matrix[i][k] == 0)
                zero_colum(k, 0, matrix.size()-1, matrix);
            zero_row(i, 0, matrix[0].size()-1, matrix);
            return;
          }
        }
    }
  }
  void zero_colum(int column, int st, int ed, vector<vector<int> >&matrix) {
    for (int i = st; i <= ed; ++i)
      matrix[i][column] = 0;
  }
  void zero_row(int row, int st, int ed, vector<vector<int> >&matrix) {
    for (int i = st; i <= ed; ++i)
      matrix[row][i] = 0;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {1, 0, 3};
  int size = sizeof(data)/sizeof(int);
  vector<int> v1(data, data+size);
  int data2[] = {1, 2, 1};
  vector<int> v2(data2, data2+size);
  vector<vector<int> > v;
  v.push_back(v1);
  //v.push_back(v2);
  Solution s;
  s.setZeroes(v);
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j)
      cout << v[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
