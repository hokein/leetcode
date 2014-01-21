#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Solution: two scan
// first: sort the array nlogn
// second. O(n) two scan, first and end iterator.
class Solution {
 public:
  typedef pair<int, int> P;
  static bool cmp(const P& a, const P& b) {
    return a.first < b.first;
  }
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<P> info;
    for (int i = 0; i < numbers.size(); ++i)
      info.push_back(P(numbers[i], i));
    sort(info.begin(), info.end(), Solution::cmp);   
    int i = 0, j = info.size()-1;
    while (i < j) {
      int sum = info[i].first + info[j].first;
      if (sum == target) {
        vector<int> ans;
        ans.push_back(min(info[i].second, info[j].second)+1);
        ans.push_back(max(info[i].second, info[j].second)+1);
        return ans;
      } else if (sum < target) {
        ++i;
      } else {
        --j;
      }
    }
    return vector<int>();
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
