// Solution: dp
// matching string a, pattern string b 
//
// dp[i][j]: whether b[1:i] and a[1:j] is matching
//
// dp[i][j] = dp[i-1][j-1], b[i] == a[j] or b[i] == '?' 
//            dp[i-1][j-1] | dp[i-1][j] | dp[i][j-1], b[i] == '*'
// dp[0][0] = 1, dp[i][0] = 1, if b[0, .., i] are all '*'
// 
//    0   a   b   c   d   e   f
// 0  1   0   0   0   0   0   0
// a  0   1   0   0   0   0   0 
// ?  0   0   1   0   0   0   0 
// c  0   0   0   1   0   0   0 
// *  0   0   0   1   1   1   1 
// f  0   0   0   0   0   0   1
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

class Solution {
 public:
  static const int N = 100000;
  int dp[3][N];
  bool isMatch(const char *s, const char *p) {
    memset(dp, 0, sizeof(dp));
    string a = " " + string(s);
    string b = " " + string(p); 
    // optimize
    int cnt = 0;
    for (int i = 1; i < b.size(); ++i)
      if (b[i] != '*')
        ++cnt;
    if (cnt > a.size()-1)
      return false;
    dp[0][0] = 1;
    int cur = 1, pre = 0;
    for (int i = 1; i < b.size(); ++i) {
      // edge consideration. special cases "", "*"
      dp[cur][0] = 0;
      if (b[i] == '*')
        dp[cur][0] = dp[pre][0];
      for (int j = 1; j < a.size(); ++j) {
        if (b[i] == a[j] || b[i] == '?') // dialog
          dp[cur][j] = dp[pre][j-1];
        else if (b[i] == '*') { // dialog, up, left
          dp[cur][j] = dp[pre][j-1] | dp[pre][j] | dp[cur][j-1];
        } else {
          dp[cur][j] = 0;
        }
      }
      swap(cur, pre);
    }
    return dp[pre][a.size()-1];
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  string a, b;
  while (cin >> a >> b) {
    Solution s;
    cout << s.isMatch(a.c_str(), b.c_str()) << endl;
  }
  return 0;
} 
