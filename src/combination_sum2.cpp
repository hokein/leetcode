#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

class Solution {
public:
  map<int, int> num2cnt;
  vector<int> subset;
  vector<vector<int> > result;
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    for (int i = 0; i < candidates.size(); ++i)
      if (num2cnt.find(candidates[i]) == num2cnt.end())
        num2cnt[candidates[i]] = 1;
      else
        ++num2cnt[candidates[i]];
    dfs(0, num2cnt.begin(), target);
    return result;
  }
  void dfs(int val, map<int, int>::iterator cur, int target) {
    if (val > target)
      return;
    if (val == target) {
      result.push_back(subset);
      return;
    }
    for (map<int, int>::iterator it = cur; it != num2cnt.end(); ++it) {
      if (it->second > 0 && val + it->first <= target) {
        --it->second;
        subset.push_back(it->first);
        dfs(val+it->first, it, target);
        subset.pop_back();
        ++it->second;
      }
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {10,1,2,7,6,1,5};

  vector<int> v(data, data+7);
  //vector<int> v(data, data+sizeof(data)/sizeof(int));
  Solution s;
  vector<vector<int> > result = s.combinationSum(v, 8);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
