#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Using bitmap generation
//
class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    // 0 means not select.
    // 1 means select.
    for (int i = 0; i < (1<<S.size()); ++i) {
      result.push_back(get_subset(i, S));
    }
    return result;
  }
  vector<int> get_subset(int bitset, vector<int>& s) {
    int cnt = 0;
    vector<int> subset;
    while (bitset) {
      if (bitset&1)
        subset.push_back(s[cnt]);
      ++cnt;
      bitset /= 2;
    }
    return subset;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {1, 2, 3};
  vector<int> data(a, a+3);
  Solution s;
  vector<vector<int> > subsets = s.subsets(data);
  for (int i = 0; i < subsets.size(); ++i) {
    for (int j = 0; j < subsets[i].size(); ++j)
      cout << subsets[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
