#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// DP: O(n)
class Solution {
 public:
  vector<int> dp;
  vector<int> ratings;
  int candy(vector<int> &ratings) {
    this->ratings = ratings;
    dp = vector<int>(ratings.size(), 0);
    int sum = 0;
    for (int i = 0; i < ratings.size(); ++i)
      sum += DP(i);
    return sum;
  }

  // Search
  int DP(int i) {
    if (dp[i] != 0) return dp[i];
    dp[i] = 1;
    if (i > 0 && ratings[i] > ratings[i-1])
      dp[i] = DP(i-1) + 1;
    if (i < ratings.size() -1 && ratings[i] > ratings[i+1])
      dp[i] = max(dp[i], DP(i+1)+1);
    return dp[i];
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {2, 2, 1};
  int size = sizeof(data)/sizeof(int);
  vector<int> a(data, data+size);
  Solution s;
  cout << s.candy(a) << endl;
  return 0;
} 
