#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Rotate 90' degree 
// 1. reflect from dialog. 
// 2. reverse each column.
//
// 1 2  =>  4 2  => 3 1
// 3 4      3 1     4 2
class Solution {
 public:
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i)    
      for (int j = 0; j < n-i-1; ++j)
        swap(matrix[i][j], matrix[n-1-j][n-1-i]);
    for (int i = 0; i < n; ++i)
      for (int k = 0, j = n-1; k < j; ++k, --j)
        swap(matrix[k][i], matrix[j][i]);
  }
  void print(vector<vector<int> > &v) {
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v[i].size(); ++j)
        cout << v[i][j] << " ";
      cout << endl;
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  vector<int> v2;
  v2.push_back(3);
  v2.push_back(4);
  vector<vector<int> > v;
  v.push_back(v1);
  v.push_back(v2);
  Solution s;
  s.rotate(v);
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j)
      cout << v[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
