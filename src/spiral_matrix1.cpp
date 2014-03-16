#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// O(1) space.
// four special corner.
//
// (i, i) ...  (i, m-1-i)
//   .              .
//   .              .
//   .              .
// (n-1-i, i) ... (n-1-i, m-1-i)
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    if (matrix.empty())
      return vector<int>();
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> result;
    int len = 0;
    while (result.size() < n*m) {
      int x = len, y = len;
      for (int j = y; j <= m-1-y; ++j)
        result.push_back(matrix[x][j]);
      for (int i = x+1; i <= n-1-x && result.size() < n*m; ++i)
        result.push_back(matrix[i][m-1-y]);
      for (int j = m-1-y-1; j >= y && result.size() < n*m; --j)
        result.push_back(matrix[n-1-x][j]);
      for (int i = n-1-x-1; i > x && result.size() < n*m; --i)
        result.push_back(matrix[i][y]);
      ++len;
    }
    return result;
  }
};

// O(n^2) space, record each position is visited. 
class Solution2 {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    if (matrix.empty())
      return vector<int>();
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool> > vis(matrix.size(), vector<bool>(matrix[0].size(), 0)); 
    vector<int> result;
    int x = 0, y = 0;
    while (result.size() < n*m) {
      while (y < m && !vis[x][y]) {
        vis[x][y] = 1;
        result.push_back(matrix[x][y]);
        ++y;
      }
      --y;
      ++x;
      while (x < n && !vis[x][y]) {
        vis[x][y] = 1;
        result.push_back(matrix[x][y]);
        ++x;
      }
      --x;
      --y;
      while (y >= 0 && !vis[x][y]) {
        vis[x][y] = 1;
        result.push_back(matrix[x][y]);
        --y;
      }
      ++y;
      --x;
      while (x >= 0 && !vis[x][y]) {
        vis[x][y] = 1;
        result.push_back(matrix[x][y]);
        --x;
      }
      ++x;
      ++y;
    }
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  vector<vector<int> > matrix;
  vector<int> v1;  
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  vector<int> v2;  
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(6);
  vector<int> v3;  
  v3.push_back(7);
  v3.push_back(8);
  v3.push_back(9);
  matrix.push_back(v1);
  //matrix.push_back(v2);
  //matrix.push_back(v3);
  Solution s;
  vector<int> ans = s.spiralOrder(matrix);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl; 
  return 0;
} 
