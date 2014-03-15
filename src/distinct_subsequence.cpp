#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// DP(n*m) with O(m) space.
//
// dp[i][j]: S[0,...,i] and T[0,...,j] matching numbers.
//
// dp[i][j] = dp[i-1][j-1] + dp[i-1][j], S[i] == T[j]
//            dp[i-1][j], else
// 0-1 knapsack problem reduce to 1-D matrix. 
class Solution {
 public:
  int numDistinct(string S, string T) {
    int n = S.size();
    int m = T.size();
    vector<int> dp(m+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
      for (int j = m-1; j >= 0; --j)
        if (T[j] == S[i])
          dp[j+1] += dp[j+1-1];
    return dp[m];
  }
};
// DP(n*m), with (n*m) space
// dp[i][j]: S[i..n-1] and T[j..m-1] matching numbers
// 
// dp[i][j] = dp[i+1][j+1] + dp[i+1][j], s[i] == t[j]
//            dp[i+1][j], else
class Solution2 {
 public:
  vector<vector<int> > dp;
  int n, m;
  string s, t;
  int numDistinct(string S, string T) {
    s = S;
    t = T;
    n = S.size();
    m = T.size();
    if (n < m)
      return 0;
    dp = vector<vector<int> >(n, vector<int>(m, -1));     
    return DP(0, 0);
  }
  int DP(int i, int j) {
    if (dp[i][j] != -1)
      return dp[i][j];
    if (i == n-1 && j == m-1)
      return dp[i][j] = (s[i] == t[j]);
    if (j == m-1)
      return dp[i][j] = DP(i+1, j) + (s[i] == t[j]);
    if (i == n-1)
      return dp[i][j] = 0;

    dp[i][j] = 0;
    if (s[i] == t[j])
      dp[i][j] += DP(i+1, j+1);
    dp[i][j] += DP(i+1, j);
    return dp[i][j];
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.numDistinct("rabbbit", "rabit") << endl;
  return 0;
} 
