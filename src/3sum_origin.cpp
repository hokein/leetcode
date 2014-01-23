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

class Solution {
 public:
  struct Info {
    int a, b, c;
    Info() {}
    Info(int aa, int bb, int cc):a(aa), b(bb), c(cc) {}
    friend bool operator != (const Info& x, const Info& y) {
      return !(x.a == y.a && x.b == y.b && x.c == y.c);
    }
    friend bool operator < (const Info& x, const Info& y) {
      if (x.a != y.a)
        return x.a < y.a;
      else if (x.b != y.b)
        return x.b < y.b;
      else
        return x.c < y.c;
    }
  };
  vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<Info> ret;
    for (int i = 0; i < num.size(); ++i) {
      int target = -num[i];
      int st = i+1, ed = num.size()-1;
      while (st < ed) {
        if (num[st] + num[ed] == target) {
          // stl::vector is too slow here, using custom data structure.
          Info info(num[i], num[st], num[ed]);
          ret.push_back(info);
          ++st;
          --ed;
        } else if (num[st] + num[ed] > target) {
          --ed;
        } else {
          ++st;
        }
      }
    }
    vector<vector<int> > ans;
    if (ret.empty()) return ans;
    sort(ret.begin(), ret.end());
    int cnt = 1;
    for (int i = 1; i < ret.size(); ++i)
      if (ret[cnt-1] != ret[i])
        ret[cnt++] = ret[i];
    for (int i = 0; i < cnt; ++i) {
      vector<int> tuples;
      tuples.push_back(ret[i].a);
      tuples.push_back(ret[i].b);
      tuples.push_back(ret[i].c);
      ans.push_back(tuples);
    }
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> data;
  int a;
  while (scanf("%d,", &a) != EOF) {
    data.push_back(a);
  }
  cout << data.size() << endl;
  Solution s;
  vector<vector<int> > ans = s.threeSum(data);
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < 3; ++j)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
