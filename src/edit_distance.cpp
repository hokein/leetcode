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
const int INF = 1000000000;
int dp[N][N];

// DP: O(n*n)
// dp[i][j]: minimum distance of word1[i,...,n1] and word2[j,...,n2].
//
class Solution {
 public:
  string a, b;
  int minDistance(string word1, string word2) {
    this->a = word1;
    this->b = word2;  
    for (int i = 0; i <= a.size(); ++i)
      for (int j = 0; j <= b.size(); ++j)
        dp[i][j] = INF;
    return DP(0, 0);
  }

  int DP(int i, int j) {
    if (i == a.size() && j == b.size()) {
      return dp[i][j] = 0;
    }
    if (dp[i][j] != INF)
      return dp[i][j];
    if (i < a.size() && j < b.size()) {
      if (a[i] == b[j])
        dp[i][j] = min(dp[i][j], DP(i+1, j+1));
      dp[i][j] = min(dp[i][j], DP(i+1, j+1)+1);
      dp[i][j] = min(dp[i][j], DP(i+1, j)+1);
      dp[i][j] = min(dp[i][j], DP(i, j+1)+1);
    } else if (i < a.size()) {
      dp[i][j] = min(dp[i][j], DP(i+1, j)+1);
    } else if (j < b.size()) {
      dp[i][j] = min(dp[i][j], DP(i, j+1)+1);
    }
    return dp[i][j];
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.minDistance("teacher", "trashes") << endl;
  return 0;
} 
