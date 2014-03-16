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
class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > matrix(n, vector<int>(n));
    int len = 0;
    int cnts = 1;
    while (cnts <= n*n) {
      int x = len, y = len;
      for (int j = y; j <= n-1-y; ++j)
        matrix[x][j] = cnts++;
      for (int i = x+1; i <= n-1-x; ++i)
        matrix[i][n-1-y] = cnts++;
      for (int j = n-1-y-1; j >= y; --j)
        matrix[n-1-x][j] = cnts++;
      for (int i = n-1-x-1; i > x; --i)
        matrix[i][y] = cnts++;
      ++len;
    }
    return matrix;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  vector<vector<int> > result = s.generateMatrix(1);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
