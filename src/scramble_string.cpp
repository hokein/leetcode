#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// DP: O(n^3) with O(n^3) space.
//
// dp[n][i][j]: s1 starts from i, s2 starts from j, length is n, is scramble. 
//              s1[i, ..., i+n-1] and s2[j, ..., j+n-1] is scramble.
// dp[n][i][j] = dp[k][i][j] && dp[n-k][i+k][j+k]
//               | dp[k][i][j+n-k] && dp[n-k][i+k][j]
class Solution {
 public:
  string s1, s2;
  int dp[35][35][35];
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size())
      return false;
    this->s1 = s1;
    this->s2 = s2;
    memset(dp, -1, sizeof(dp));
    return DP(s1.size(), 0, 0);
  }
  int DP(int n, int i, int j) {
    if (n == 1)
      return dp[n][i][j] = s1[i] == s2[j];
    if (dp[n][i][j] != -1)
      return dp[n][i][j]; 
    for (int k = 1; k < n && dp[n][i][j] != 1; ++k) {
      dp[n][i][j] = DP(k, i, j) && DP(n-k, i+k, j+k); 
      if (dp[n][i][j])
        return true;
      dp[n][i][j] = DP(k, i, j+n-k) && DP(n-k, i+k, j);
    }
    return dp[n][i][j]; 
  }
};

// DP: O(n^4) with O(n^4) space.
//
// dp[i][j][ii][jj]: s1[i...(j-1)] and s2[ii...(jj-1)] is scramble.
//
// dp[i, j, ii, jj] = dp[i, i+k, ii, ii+k] && dp[i+k, j, ii+k, jj]
//                    | dp[i, i+k, jj-k, jj] && dp[i+k, j, ii, jj-k], i < i+k < j
int dp[35][35][35][35];
class Solution2 {
 public:
  string s1, s2;
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size())
      return false;
    this->s1 = s1;
    this->s2 = s2;
    memset(dp, -1, sizeof(dp));
    return DP(0, s1.size(), 0, s2.size());
  }

  int DP(int i, int j, int ii, int jj) {
    if (j-i == 1)
      return dp[i][j][ii][jj] = (s1[i] == s2[ii]);
    if (dp[i][j][ii][jj] != -1)
      return dp[i][j][ii][jj];
    for (int k = 1; k < j-i; ++k) {
      dp[i][j][ii][jj] = DP(i, i+k, ii, ii+k) && DP(i+k, j, ii+k, jj);
      if (dp[i][j][ii][jj])
        return true;
      dp[i][j][ii][jj] = DP(i, i+k, jj-k, jj) && DP(i+k, j, ii, jj-k);
      if (dp[i][j][ii][jj])
        return true;
    }
    return dp[i][j][ii][jj];
  }
};

Solution s;
int main() {
  freopen("test.txt", "r", stdin);

  cout << s.isScramble("abc", "bca") << endl;
  cout << s.isScramble("bdac", "abcd") << endl;
  cout << s.isScramble("bbbaaaaccaabbbaa", "baababaababacabc") << endl;
  return 0;
} 
