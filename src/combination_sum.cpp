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
  vector<int> subset;
  vector<vector<int> > result;
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    nums = candidates;
    sort(nums.begin(), nums.end());
    dfs(0, 0, target);
    return result;
  }
  void dfs(int val, int cur, int target) {
    if (val == target) {
      result.push_back(subset);
      return;
    }
    for (int i = cur; i < nums.size(); ++i) {
      if (val + nums[i] <= target) {
        subset.push_back(nums[i]);
        dfs(val+nums[i], i, target);
        subset.pop_back();
      }
      else
        break;
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {2, 3, 6, 7};
  vector<int> v(data, data+4);
  Solution s;
  vector<vector<int> > result = s.combinationSum(v, 7);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
