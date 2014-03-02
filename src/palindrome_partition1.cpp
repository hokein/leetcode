#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// DP Solution
//
// how to determine s[i..j] is palindromic or not:
// use DP, is_palindrom[i][j] = s[i] == s[j] && s[i+1][j-1]
class Solution {
 public:
  static const int N = 1000;
  int is_palindrom[N][N];
  string str;
  vector<vector<string> > partition(string s) {
    str = s;
    memset(is_palindrom, -1, sizeof(is_palindrom));
    int n = s.size(); 
    vector<vector<string> > dp[N]; // sub palindromic strings in str[i,n-1]
    // sub palinromic strings in s[i...n-1] is:
    // Generate s[i..j] * sub palinromic strings in s[j, n-1]
    for (int i = n-1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        if (isPalindrome(i, j)) {
          string palindrome = s.substr(i, j-i+1);
          if (j+1 < n) {
            for (int k = 0; k < dp[j+1].size(); ++k) {
              vector<string> cur(1, palindrome);
              cur.insert(cur.end(), dp[j+1][k].begin(), dp[j+1][k].end());
              dp[i].push_back(cur);
            }
          } else {
            vector<string> cur(1, palindrome);
            dp[i].push_back(cur);
          }
        }
      }
    }
    return dp[0];
  }

  bool isPalindrome(int i, int j) {
    if (i == j || (j-i == 1 && str[i] == str[j])) {
      is_palindrom[i][j] = 1;
      return 1;
    }
    if (is_palindrom[i][j] != -1)
      return is_palindrom[i][j];
    return is_palindrom[i][j] = (str[i] == str[j] && isPalindrome(i+1, j-1));
  }
};

// DFS solution, O(2^n)
class Solution2 {
public:
  string str;
  vector<vector<string> > partition(string s) {
    str = s;
    return dfs(0);
  }
  vector<vector<string> > dfs(int cur_pos) {
    vector<vector<string> > result;
    for (int len = 0; len+cur_pos < str.size(); ++len) {
      int end = cur_pos + len;
      if (isPalindrome(cur_pos, end)) {
        if (end == str.size() - 1) {
          vector<string> cur(1, string(str.begin()+cur_pos, str.begin()+end+1));
          result.push_back(cur);
          break;
        }
        vector<vector<string> > next = dfs(end+1);
        for (int i = 0; i < next.size(); ++i) {
          vector<string> cur(1, string(str.begin()+cur_pos, str.begin()+end+1));
          cur.insert(cur.end(), next[i].begin(), next[i].end());
          result.push_back(cur);
        }
      }
    }
    return result;
  }
  bool isPalindrome(int start, int end) {
    for (int i = start, j = end; i <= j; ++i, --j) {
      if (str[i] != str[j])
        return false;
    }
    return true;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  vector<vector<string> > result = s.partition("ababab");
  for (int i = 0; i < result.size(); ++i) {
    cout << "[ ";
    for (int j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << "]" << endl;
  }
  return 0;
} 
