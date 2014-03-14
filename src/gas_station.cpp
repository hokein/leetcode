#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// O(n) solution.
class Solution {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int sum = 0; // total sum
    int big_zero = 0; // record interval sum, make sure >= 0
    int st_pos = 0;
    for (int i = 0; i < gas.size(); ++i) {
      sum += gas[i] - cost[i];
      big_zero += gas[i] - cost[i];
      if (big_zero < 0) {
        st_pos = i+1;
        big_zero = 0;
      }
    }
    return sum >= 0?st_pos:-1;
  }
};

// O(n) solution.
class Solution3 {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int cnts = 0;
    int n = gas.size();
    vector<bool> vis(n, 0);
    // start at the end position.
    int st_pos = n-1;
    int sum = 0;
    int cur = st_pos;
    while (cnts <= n) {
      // forward cur until can not reach.
      while (sum+gas[cur] >= cost[cur] && cnts < n) {
        vis[cur] = 1;
        ++cnts;
        sum += gas[cur]-cost[cur];
        cur = (cur+1)%n;
      }
      if (cnts >= n)
        return sum >= 0? st_pos:-1;

      // move st_pos forward to see we can more gas.
      --st_pos;
      if (st_pos < 0 || vis[st_pos] == 1)
        return -1;
      ++cnts;
      vis[st_pos] = 1;
      sum += gas[st_pos]-cost[st_pos];
    }
    return -1;
  }
};

// O(n*n) solution: TLE
class Solution2 {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    for (int pos = 0; pos < gas.size(); ++pos) {
      vector<int> dp(gas.size(), -1);
      dp[pos] = gas[pos];
      for (int i = 1; i <= gas.size(); ++i) {
        int cur_pos = (pos+i)%gas.size();
        int pre_pos = (cur_pos-1+gas.size())%gas.size();
        if (i == gas.size() && dp[pre_pos]-cost[pre_pos] >= 0)
          return pos;
        if (dp[pre_pos] - cost[pre_pos] >= 0) 
          dp[cur_pos] = dp[pre_pos] - cost[pre_pos] + gas[cur_pos];
      }
    }    
    return -1;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  //int data1[] = {1, 3, 2}; //gas 
  //int data2[] = {2, 3, 1}; //cost
  int data1[] = {1, 2, 3, 4, 5}; //gas 
  int data2[] = {3, 4, 5, 1, 2}; //cost
  int size = sizeof(data1)/sizeof(int);
  Solution s;
  vector<int> a(data1, data1+size);
  vector<int> b(data2, data2+size);
  cout << s.canCompleteCircuit(a, b) << endl;
  return 0;
} 
