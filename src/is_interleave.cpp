#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 500;
int dp[N][N];
int cnt = 0;

// DP: O(n*n)
//
// dp[i][j]: s1[i..n1], s2[j..n2] is interleaving with s3[i+j,..,n3].
// dp[i][j] = dp[i+1][j], s1[i] == s3[i+j]
//            | dp[i][j+1], s2[j] == s3[i+j]
// dp[n1][n2] = 1.
class Solution {
public:
  string s1, s2, s3;

  bool isInterleave(string s1, string s2, string s3) {
    memset(dp, 0, sizeof(dp));
    if (s3.size() != s1.size() + s2.size())
      return false;
    dp[s1.size()][s2.size()] = 1;
    for (int i = s1.size(); i >= 0; --i)
      for (int j = s2.size(); j >= 0; --j) {
        if (i == s1.size() && j == s2.size())
          continue;
        if (j+1 <= s2.size() && s2[j] == s3[i+j])
          dp[i][j] |= dp[i][j+1];
        if (i+1 <= s1.size() && s1[i] == s3[i+j])
          dp[i][j] |= dp[i+1][j];
      }
    return dp[0][0];
  }
};

class Solution2 {
public:
  string s1, s2, s3;

  bool isInterleave(string s1, string s2, string s3) {
    memset(dp, -1, sizeof(dp));
    this->s1 = s1;
    this->s2 = s2;
    this->s3 = s3;
    return DP(0, 0);
  }

  // Search
  int DP(int i, int j) {
    if (i+j == s3.size()) {
      if (i == s1.size() && j == s2.size())
        return dp[i][j] = 1;
      else
        return 0;
    }
    if (dp[i][j] != -1)
      return dp[i][j];

    if (i < s1.size() && s1[i] == s3[i+j])
      dp[i][j] = DP(i+1, j);

    if (dp[i][j] != 1 && j < s2.size() && s2[j] == s3[i+j])
      dp[i][j] = DP(i, j+1);

    if (dp[i][j] != 1)
      dp[i][j] = 0;
    return dp[i][j];
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  
  string s1, s2, s3;
  Solution s;
  cin >> s1 >> s2 >> s3;
  //cout << s.isInterleave("aa", "bb", "abcc") << endl;
  //cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
  //cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
  cout << s.isInterleave(s1, s2, s3) << endl;
  return 0; } 
