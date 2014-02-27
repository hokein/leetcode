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
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";
    string ans;
    int pos = 0;
    while (pos < strs[0].size()) {
      int is_valid = true;
      for (int i = 1; i < strs.size() && is_valid; ++i) {
        if (pos < strs[i].size())
          is_valid &= (strs[i][pos] == strs[i-1][pos]);
        else
          is_valid = false;
      }
      if (!is_valid)
        return ans;
      ans = ans + string(1, strs[0][pos++]);
    }
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<string> v;
  v.push_back("");
  //v.push_back("c");
  Solution s;
  cout << s.longestCommonPrefix(v) << endl;
  return 0;
} 
