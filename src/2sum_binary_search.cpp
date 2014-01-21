#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Two sum: nlogn 
// binary search
class Solution {
 public:
  typedef pair<int, int> P;
  static bool cmp(const P& a, const P& b) {
    return a.first < b.first;
  }
  int search(vector<P>& info, int l, int r, int value) {
    while (l < r) {
      int mid = (l+r)/2;
      if (info[mid].first == value)
        return mid;
      else if (info[mid].first < value)
        l = mid+1;
      else
        r = mid;
    }
    return -1;
  }
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<P> info;
    for (int i = 0; i < numbers.size(); ++i)
      info.push_back(P(numbers[i], i));
    sort(info.begin(), info.end(), Solution::cmp);   
    vector<int> ans;
    for (int i = 0; i < info.size(); ++i) {
      int pos = search(info, i+1, info.size(), target-info[i].first);
      if (pos != -1) {
        ans.push_back(info[i].second+1);
        ans.push_back(info[pos].second+1);
        sort(ans.begin(), ans.end());
        break;
      }
    }
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> data;
  int a;
  while (cin >> a) {
    data.push_back(a);
  }
  Solution s;
  // 5 75 25
  // find 100
  vector<int> ans = s.twoSum(data, 100);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
