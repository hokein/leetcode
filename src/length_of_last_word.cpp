#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

class Solution {
 public:
  int lengthOfLastWord(const char *s) {
    int len = strlen(s);      
    int pos = len-1;
    while (pos >= 0 && s[pos] == ' ') {
      --pos;
    }
    int cur = pos;
    while (cur >= 0 && s[cur] != ' ') {
      --cur;
    }
    return pos-cur;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  char* p = " abc ";
  Solution s;
  cout << s.lengthOfLastWord(p);
  return 0;
} 
