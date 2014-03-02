#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// DP solution
// dp[i]: means the number of palindrome string s in s[1, i] .
//
// dp[j] = min(dp[i-1]+1), a[i...j] is palindromic.
//
// The minCut is dp[n]-1.
class Solution {
 public:
  string str;
  static const int N = 10000;
  vector<int> match_pos[N];

  int minCut(string s) { 
    str = s;
    calculate_match_pos();
    vector<int> dp(str.size()+1, str.size()+1);
    dp[0] = 0;
    for (int i = 0; i < str.size(); ++i) {
      for (int j = 0; j < match_pos[i].size(); ++j) {
        int end = match_pos[i][j];
        dp[end+1] = min(dp[end+1], dp[i-1+1]+1);
      }
    }
    return dp[str.size()]-1;
  }

  void calculate_match_pos() {
    for (int i = 0; i < str.size(); ++i) {
      int ii = i;
      int jj = i+1;
      match_pos[ii].push_back(ii);
      // even number
      while (ii >= 0 && jj < str.size() && str[ii] == str[jj]) {
        match_pos[ii].push_back(jj);
        --ii;
        ++jj;
      }
      // odd number
      ii = i-1;
      jj = i+1;
      while (ii >= 0 && jj < str.size() && str[ii] == str[jj]) {
        match_pos[ii].push_back(jj);
        --ii;
        ++jj;
      }
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.minCut("abcccb") << endl;
  //cout << s.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi") << endl;
  return 0;
} 
