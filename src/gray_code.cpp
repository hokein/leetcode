#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// reflect-and-prefix method.
// generate n bits gray code from n-1 bits gray code.
//
// 1bit:    2bits:  3bits:
//  0         00       000
//  1         01       001
//            11       011
//            10       010
//                     110
//                     111
//                     101
//                     100
class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> result;
    result.push_back(0);
    for (int i = 0; i < n; ++i) {
      int mask = 1<<i;
      for (int j = result.size()-1; j >= 0; --j) 
        result.push_back(mask|result[j]);
    }
    return result;
  }
};

// Gray code
// generate gray code from binary
// binary: b0b1b2b3...bn
// gray:   b0(b0^b1)(b1^b2)
class Solution2 {
public:
  vector<int> grayCode(int n) {
    vector<int> result;
    for (int i = 0; i < (1<<n); ++i)
      result.push_back(binary_to_gray(i));
    return result;
  }
  int binary_to_gray(int v) {
    return v^(v>>1);
  }
};

// Brute-force method.
class Solution3 {
public:
  set<int> vis;
  int n;
  vector<int> result;
  vector<int> grayCode(int n) {
    this->n = n;
    result.push_back(0);
    vis.insert(0);
    dfs(0);
    return result;
  }
  void dfs(int val) {
    for (int i = 0; i < n; ++i) {
      int mask = (1<<i);
      int new_val = ((val^mask)&mask)|(val&(~mask));
      if (vis.find(new_val) == vis.end()) {
        result.push_back(new_val);
        vis.insert(new_val);
        dfs(new_val);
        break;
      }
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  vector<int> ans = s.grayCode(3);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
} 
