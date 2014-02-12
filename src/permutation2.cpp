#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

class Solution {
 public:
  map<int, int> num2cnt; // <nums, cnts>
  vector<int> sequence;
  vector<vector<int> > ret;
  int n;
  vector<vector<int> > permuteUnique(vector<int> &num) {
    num2cnt.clear();
    n = num.size();
    sequence = vector<int>(num.size());
    for (int i = 0; i < num.size(); ++i)
      if (num2cnt.find(num[i]) == num2cnt.end()) {
        num2cnt[num[i]] = 1;
      } else {
        ++num2cnt[num[i]];
      }
    dfs(0);
    return ret;
  }

  void dfs(int cur) {
    if (cur >= n) {
      ret.push_back(sequence);
      return;
    }
    for (map<int, int>::iterator it = num2cnt.begin(); it != num2cnt.end(); ++it) {
      if (it->second > 0) {
        --it->second;
        //--num2cnt[it->first];
        sequence[cur] = it->first;
        dfs(cur+1);
        ++it->second;
        //++num2cnt[it->first];
      }
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> data;
  //for (int i = 0; i < 3; ++i)
    //data.push_back(i+1);
  data.push_back(1);
  data.push_back(1);
  data.push_back(2);
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

