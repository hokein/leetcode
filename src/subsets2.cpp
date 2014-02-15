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

// for subsets without duplicate elements.
// Each element can be selected or not selected(0, 1 times).
//
// The same with duplicated elements.
// Each element can be selectd 0~num times.
//
class Solution {
 public:
  map<int, int> num2cnt;
  vector<vector<int> > result; 
  vector<int> sequence;
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    num2cnt.clear();
    // record each number appears times.
    for (int i = 0; i < S.size(); ++i) {
      if (num2cnt.find(S[i]) == num2cnt.end())
        num2cnt[S[i]] = 1;
      else
        ++num2cnt[S[i]];
    }
    dfs(num2cnt.begin());
    return result;
  }
  void dfs(map<int, int>::iterator cur) {
    result.push_back(sequence);
    // Each number can be selected 0~num times.
    for (map<int, int>::iterator it = cur; it != num2cnt.end(); ++it) {
      for (int i = it->second; i > 0; --i) {
        sequence.push_back(it->first);
        ++it;
        dfs(it);
        --it;
      }
      for (int i = it->second; i > 0; --i)
        sequence.pop_back();
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {1, 2, 2};
  vector<int> data(a, a+3);
  Solution s;
  vector<vector<int> > subsets = s.subsetsWithDup(data);
  for (int i = 0; i < subsets.size(); ++i) {
    for (int j = 0; j < subsets[i].size(); ++j)
      cout << subsets[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
