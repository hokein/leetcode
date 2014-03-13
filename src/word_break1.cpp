#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// DP: O(n^2)
//
// dp[i]: s[0..i-1] can break validly.
//
// dp[i] = dp[j]&(s[j..i-1] is a word).
class Solution {
 public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> dp(s.size()+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && dict.find(string(s.begin()+j, s.begin+i)) != dict.end()) {
          dp[i] = 1;
          break;
        } 
      }
    }
    return dp[s.size()];
  }
};

// DFS: O(2^n), TLE
class Solution {
 public:
  string ss;
  bool wordBreak(string s, unordered_set<string> &dict) {
    ss = s;
    return dfs(0, ss.size(), dict);  
  }
  bool dfs(int st, int ed, unordered_set<string> &dict) {
    if (st >= ed)
      return true;

    for (int i = st+1; i < ed; ++i) {
      if (dict.find(string(ss.begin()+st, ss.begin()+i)) != dict.end()) {
        if (dfs(i, ed, dict))
          return true;
      }
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  return 0;
} 
