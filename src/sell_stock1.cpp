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
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2)
      return 0;
    int mini = prices[0];
    int maxx = 0;
    // find the maxximum pair(small, big), big-small is largest.
    for (int i = 1; i < prices.size(); ++i) {
      maxx = max(prices[i]-mini, maxx); 
      mini = min(prices[i], mini);
    }
    return maxx;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {3, 2, 3};
  vector<int> v(data, data+3);
  Solution s;
  cout << s.maxProfit(v) << endl;
  return 0;
} 
