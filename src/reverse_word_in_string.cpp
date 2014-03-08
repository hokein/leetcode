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
  void reverseWords(string &s) {
    string ss;
    // remove prefix/postfix extra blanks.
    int i = 0;
    while (s[i] == ' ')
      ++i;
    int ed = s.size()-1;
    while (s[ed] == ' ')
      --ed;
    // reduce multiple spaces to one space.
    for (int k = i; k <= ed; ++k)
      if (s[k] != ' ' || (k-1>=0 && s[k] == ' ' && s[k-1] != ' '))
        ss.push_back(s[k]);
    reverse(ss.begin(), ss.end());
    int pos = 0;    
    while (pos < ss.size()) {
      if (ss[pos] == ' ') {
        ++pos;
        continue;
      }
      int end_pos = pos;
      while (end_pos < ss.size() && ss[end_pos] != ' ')
        ++end_pos;
      for (int i = pos, j = end_pos-1; i < j; ++i, --j)
        swap(ss[i], ss[j]);
      pos = end_pos+1;
    }
    s = ss;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  string ss = "abc   dd  ";
  s.reverseWords(ss);
  cout << ss << endl;
  return 0;
} 
