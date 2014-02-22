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
  vector<int> getRow(int rowIndex) {
    vector<int> prev, cur;
    for (int i = 0; i <= rowIndex; ++i) {
      cur.clear();
      cur.push_back(1);
      for (int j = 1; j < i; ++j)
        cur.push_back(prev[j-1]+prev[j]);
      if (i != 0)
        cur.push_back(1);
      prev = cur;
    }
    return cur;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;

  vector<int> ans = s.getRow(3);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
} 
