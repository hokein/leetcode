#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// DP solution.
//
//
// A mathematic solution: C(m-1+n-1, m-1):
//   The robot need to walk left n-1 steps, down m-1 steps.
//   So there are n-1+m-1 total steps, in total steps we need to select m-1 steps
//   to walk down.
// 
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        dp[i][j] += dp[i-1][j] + dp[i][j-1];
    return dp[m][n];
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.uniquePaths(3, 7) << endl;
  return 0;
} 
