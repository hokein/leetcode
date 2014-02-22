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
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ans;
    for (int i = 0; i < numRows; ++i) {
      ans.push_back(vector<int>());
      ans.back().push_back(1);
      for (int j = 1; j < i; ++j) {
        ans.back().push_back(ans[i-1][j-1]+ans[i-1][j]);
      }
      if (i != 0)
        ans.back().push_back(1);
    }      
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  vector<vector<int> > ans = s.generate(5);
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
