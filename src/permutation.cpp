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
  vector<int> nums;
  vector<int> sequence;
  vector<vector<int> > ret;
  static const int N = 100;
  bool vis[N];
  vector<vector<int> > permute(vector<int> &num) {
     nums = num; 
     memset(vis, 0, sizeof(vis));
     sequence = vector<int>(num.size());
     ret.clear();
     dfs(0);
     return ret;
  }

  void dfs(int cur) {
    if (cur >= nums.size()) {
      ret.push_back(sequence);
      return;
    }
    for (int i = 0; i < nums.size(); ++i)  
      if (!vis[i]) {
        sequence[cur] = nums[i];
        vis[i] = 1;
        dfs(cur+1);
        vis[i] = 0;
      }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> data;
  for (int i = 0; i < 3; ++i)
    data.push_back(i+1);
  Solution s;
  vector<vector<int> > ret = s.permute(data);
  for (int i = 0; i < ret.size(); ++i) {
    for (int j = 0; j < ret[i].size(); ++j) {
      cout << ret[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
} 
