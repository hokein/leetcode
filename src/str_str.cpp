#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// KMP algorithm: O(n+m).
class Solution {
 public:
  vector<int> prefix;
  char *strStr(char *haystack, char *needle) {
    int m = strlen(needle);
    int n = strlen(haystack);
    // pattern needle can be empty string "". 
    if (m == 0)
      return haystack;
    int q = -1;
    cal_prefix(needle, m);
    for (int i = 0; i < n; ++i) {
      while (q >= 0 && needle[q+1] != haystack[i])
        q = prefix[q];
      if (needle[q+1] == haystack[i])
        ++q;
      if (q == m-1) 
        return &haystack[i-(m-1)];
    }
    return NULL;
  }
  void cal_prefix(char* p, int size) {
    prefix = vector<int>(size, 0);
    prefix[0] = -1;
    int k = -1;
    for (int i = 1; i < size; ++i) {
      while (k >= 0 && p[k+1] != p[i])
        k = prefix[k];
      if (p[k+1] == p[i])
        ++k;
      prefix[i] = k;
    }
  }
};

// O(n^2): TLE
class Solution2 {
 public:
  char *strStr(char *haystack, char *needle) {
    char* p1 = haystack;
    while (*p1) {
      char* p = p1;
      char* p2 = needle;    
      while (*p&& *p2 && *p == *p2) {
        ++p;
        ++p2;
      }
      if (!(*p2))
        return p1;
      ++p1;
    }
    return NULL;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  char a[] = "a";
  char b[] = "";
  cout << s.strStr(a, b) << endl;
  return 0;
} 
