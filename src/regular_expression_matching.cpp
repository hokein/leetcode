#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Regular matching, DP
//
// dp[i][j]: s[1...i] is matching with p[1...j]
//
//
class Solution {
 public:
  bool isMatch(const char *s, const char *p) {
    int n = strlen(s);
    int m = strlen(p);
    vector<vector<bool> > dp(n+1, vector<bool>(m+1, 0));  
    dp[0][0] = 1;
    for (int j = 2; j <= m; j+=2) {
      if (p[j-1] == '*')
        dp[0][j-1] = dp[0][j] = 1;
      else
        break;
    }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        if (s[i-1] == p[j-1] || p[j-1] == '.') {
          dp[i][j] = dp[i][j] | dp[i-1][j-1];
        }
        if (p[j-1] == '*') {
          // one character. 
          dp[i][j] = dp[i][j] | dp[i][j-1];
          // zero character.
          if (j-2 >= 0)
            dp[i][j] = dp[i][j] | dp[i][j-2];
          if (j-2 >= 0 && (s[i-1] == p[j-2] || p[j-2] == '.'))
            dp[i][j] = dp[i][j] | dp[i-1][j];
        }
      }
    return dp[n][m];
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.isMatch("", "c*c*") << endl;
  cout << s.isMatch("aa", "a") << endl;
  cout << s.isMatch("aa", "aa") << endl;
  cout << s.isMatch("aaa", "aa") << endl;
  cout << s.isMatch("aa", "a*") << endl;
  cout << s.isMatch("aa", ".*") << endl;
  cout << s.isMatch("ab", ".*") << endl;
  cout << s.isMatch("aab", "c*a*b") << endl;
  cout << s.isMatch("aaa", "ab*ac*a") << endl;
  return 0;
} 
