#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// 4sum problem, 3sum variation.
//
// Reduce to 3sum => 2sum.
// Using two scan, O(n*n*n).
class Solution {
 public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    vector<vector<int> > ret;
    vector<int> tuples(4);
    for (int i = 0; i < num.size(); ++i) {
      // optimize: ignore repulicate elements since it has been calulated
      // at previous times.
      if (i > 0 && num[i] == num[i-1])
        continue;
      for (int j = i+1; j < num.size(); ++j) {
        int find_value = target - num[j] - num[i];
        int st = j + 1, ed = num.size() - 1;
        while (st < ed) {
          if (num[st] + num[ed] == find_value) {
            tuples[0] = num[i];
            tuples[1] = num[j];
            tuples[2] = num[st];
            tuples[3] = num[ed];
            ret.push_back(tuples);
            ++st;
            --ed;
          } else if (num[st] + num[ed] > find_value) {
            --ed;
          } else {
            ++st;
          }
        }
      }
    }
    if (ret.empty())
      return vector<vector<int> > ();
    sort(ret.begin(), ret.end());
    // reduce replicated elements.
    int len = 1;
    for (int i = 1; i < ret.size(); ++i)
      if (ret[len-1] != ret[i])
        ret[len++] = ret[i];
    return vector<vector<int> >(ret.begin(), ret.begin()+len);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> data;
  int a;
  while (scanf("%d,", &a) != EOF) {
    data.push_back(a);
  }
  Solution s;
  vector<vector<int> > ans = s.fourSum(data, 0);
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < 4; ++j)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
} 

