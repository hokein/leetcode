#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// 3sum problem:
// find all triples(a, b, c) in a given array, which satifs a+b+c=0
//
// Two Solutions:
//  a + b = -c
// 1. Binary Search 
//   1) calulated all two different element sum (a[i]+a[j]), insert to a set, O(n*n).
//   2) determine whether -c is in the set(log(n*n)). Also we can use binary search 
// 2. For 2sum problem, we solve it in O(n) through Two scan method:
//   Using two pointer, one points front, the other points end.
//   p[i]+p[j] = 0, find one, ++i, ++j
//   p[i]+p[j] > 0, --j;
//   p[i]+p[j] < 0, ++j;
//
//   we also use it in 3sum problem, solve in O(n*n).
//   enum c: p[i]+p[j] ? c
class Solution {
 public:
  vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int> > ret;
    vector<int> tuples(3);
    for (int i = 0; i < num.size(); ++i) {
      // optimize: ignore repulicate elements since it has been calulated
      // at previous times.
      if (i > 0 && num[i] == num[i-1])
        continue;
      int target = -num[i];
      int st = i+1, ed = num.size()-1;
      while (st < ed) {
        if (num[st] + num[ed] == target) {
          tuples[0] = num[i];
          tuples[1] = num[st];
          tuples[2] = num[ed];
          ret.push_back(tuples);
          ++st;
          --ed;
        } else if (num[st] + num[ed] > target) {
          --ed;
        } else {
          ++st;
        }
      }
    }
    if (ret.empty())
      return vector<vector<int> >();
    sort(ret.begin(), ret.end());
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
  vector<vector<int> > ans = s.threeSum(data);
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < 3; ++j)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
} 

