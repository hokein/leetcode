#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Cantor decode. Calculate kth permutation
// 
// X = a[n]*(n-1)! + a[n-1]*(n-2)! + ... + a[1]*0!
//
// decode: kth permutation
// --k;
// k/(n-1)! : find k/(n-1)! th unused minimum element.
//
// k = k%(n-1)!
//
// k/(n-2)! : find k/(n-2)! th unused minimum element.
//
// k = k%(n-2)!
//
// ... 
class Solution {
 public:
  string getPermutation(int n, int k) {
    const int facts[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; 
    int sum = 0;
    --k;
    string ans;
    bool vis[10] = {0};
    for (int i = 1; i <= n; ++i) {
      int cnt = k/facts[n-i];
      int times = 0;
      for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (times == cnt) {
          vis[i] = 1;
          ans.push_back(i+'0');
          break;
        }
        ++times;
      }
      k %= facts[n-i];
    } 
    return ans;
  }
};

class Solution2 {
 public:
  string getPermutation(int n, int k) {
    const int facts[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; 
    int sum = 0, begin_n = 1;
    // Calculate the begin number, optimization.
    while (sum < k) {
      if (sum+facts[n-1] >= k)
        break;
      sum += facts[n-1];
      ++begin_n;
    }
    vector<int> nums;
    nums.push_back(begin_n);
    for (int i = 0; i < n; ++i) {
      if (i+1 != begin_n)
        nums.push_back(i+1);
    }
    int cnts = sum;
    do {
      ++cnts;
      if (cnts == k)
        break;
    } while (next_permutation(nums.begin(), nums.end()));
    string ans;
    for (int i = 0; i < n; ++i)
      ans.push_back('0'+nums[i]);
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.getPermutation(3, 6) << endl;
  return 0;
} 
