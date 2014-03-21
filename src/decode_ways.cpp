#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// DP: O(n)
//
// dp[i]: the number of decodings of s[1...i].
//
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty())
      return 0;
    vector<int> dp(s.size()+1, 0);    
    dp[0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
      // Be careful with 0
      if (s[i-1] != '0')
        dp[i] += dp[i-1];
      if (i-2 >= 0 && s[i-2] != '0') {
        int val = 10*(s[i-2]-'0')+s[i-1]-'0';
        if (val <= 26)
          dp[i] += dp[i-2];
      }
    }
    return dp[s.size()];
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  Solution s;
  cout << s.numDecodings("0") << endl;

  return 0;
} 
