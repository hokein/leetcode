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
  vector<int> combination;
  vector<vector<int> > result;
  int max_len;
  vector<vector<int> > combine(int n, int k) {
    max_len = k;
    combination = vector<int>(k);
    dfs(0, n);
    return result;
  }

  void dfs(int cur, int n) {
    if (cur == max_len) {
      result.push_back(combination);
      return;
    }
    // keep order.
    for (int i = cur==0?cur+1:combination[cur-1]+1; i <= n; ++i) {
      combination[cur] = i;
      dfs(cur+1, n);
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  vector<vector<int> > result = s.combine(4, 3);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
