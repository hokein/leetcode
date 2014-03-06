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
  int minPathSum(vector<vector<int> > &grid) {
    static const int INF = 1000000000;
    vector<vector<int> > dp(grid.size(), vector<int>(grid[0].size(), INF));    
    dp[0][0] = grid[0][0];
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[i].size(); ++j) {
        if (j > 0)
          dp[i][j] = min(dp[i][j], dp[i][j-1]+grid[i][j]); 
        if (i > 0)
          dp[i][j] = min(dp[i][j], dp[i-1][j]+grid[i][j]);
      }
    return dp[grid.size()-1][grid[0].size()-1];
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);

  vector<int> v2;
  v2.push_back(3);
  v2.push_back(4);

  vector<vector<int> > v;
  v.push_back(v1);
  v.push_back(v2);

  Solution s;
  cout << s.minPathSum(v) << endl;
  return 0;
} 
