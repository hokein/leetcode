#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Manacher's algorithm: O(n)
// Reference: http://www.felix021.com/blog/read.php?2040 
class Solution {
 public:
  // extend "abcb" to "$#a#b#c#b#!"
  string extend(const string& s) {
    string str;
    for (int i = 0; i < s.size(); ++i) {
      str.push_back('#');
      str.push_back(s[i]);
    }
    return "$" + str + "#!";
  }
  string longestPalindrome(string s) {
    string ss = extend(s);
    vector<int> p(ss.size());
    // mid: middle position of current maximum palindromic string.
    // mx: mid+p[i], the edge of palindromic s.
    int mid = 0, mx = 0;
    for (int i = 1; i < ss.size()-1; ++i) {
      p[i] = mx < i?1:min(mx-i, p[2*mid-i]);
      while (ss[p[i]+i] == ss[i-p[i]]) {
        ++p[i];
      }
      if (i+p[i] > mx) {
        mx = i + p[i];
        mid = i;
      }
    }
    int max_mid = -1;
    int max_len = 0;
    for (int i = 1; i < ss.size()-1; ++i) {
      if (max_len < p[i])
        max_len = p[max_mid=i];
    }
    return s.substr((max_mid-2)/2-(max_len-1-1)/2, max_len-1);
  }
};

// O(N^2)
// The worse case is "aa...aaa"
class Solution2 {
 public:
  string longestPalindrome(string s) {
    int st_pos = 0, ed_pos = 0;
    for (int i = 0; i < s.size(); ++i) {
      int ii = i;
      int jj = i+1;
      while (ii >= 0 && jj < s.size() && s[ii] == s[jj]) {
        if (jj - ii > ed_pos - st_pos) {
          st_pos = ii;
          ed_pos = jj;
        }
        --ii;
        ++jj;
      }
      ii = i-1; jj = i+1;
      while (ii >= 0 && jj < s.size() && s[ii] == s[jj]) {
        if (jj - ii > ed_pos - st_pos) {
          st_pos = ii;
          ed_pos = jj;
        }
        --ii;
        ++jj;
      }
    }      
    return s.substr(st_pos, ed_pos-st_pos+1);
  }
};
 
int main() {
  freopen("test.txt", "r", stdin);
  Solution s;
  cout << s.longestPalindrome("abcb") << endl;
  return 0;
} 
