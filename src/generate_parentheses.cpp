#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Generate all the valid n-pairs parentheses sequence.
// Catalan number, there are C(2n, n)/(n+1) different kinds of sequences.
class Solution {
 public:
  vector<string> result;
  int n;
  vector<string> generateParenthesis(int n) {
    this->n = n;
    dfs("", 0);
    return result;    
  }

  void dfs(string s, int left_cnts) {
    if (left_cnts > n)
      return;
    if (s.size() == 2*n) {
      result.push_back(s);
      return;
    }
    int right_cnt = s.size() - left_cnts;
    if (right_cnt < left_cnts)
      dfs(s+")", left_cnts);
    dfs(s+"(", left_cnts+1);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  vector<string> ret = s.generateParenthesis(3);
  for (int i = 0 ; i < ret.size(); ++i)
    cout << ret[i] << endl; 
  return 0;
} 
