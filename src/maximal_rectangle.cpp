#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// find largest all-1s rectangle in a given 01 matrix.
//
// Change to 1D largest rectangle problem(O(n) solution using stack)
//
// sum[i][j]: max(number of 1s in row[k..i][j], row[k...i][j] = 1);
// means height[i][j].
// We can reduce sum to O(n) space.
class Solution {
 public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.empty())
      return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> sum(m+1, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int k = 0; k < m; ++k) {
        if (matrix[i][k] == '0')
          sum[k] = 0;
        else 
          sum[k] = i == 0?1:sum[k]+1;
      }

      // largest rectangle problem.
      stack<int> s;
      int k = 0;
      // last sum[m] = 0, for pop case.
      while (k <= m) {
        if (s.empty() || sum[s.top()] < sum[k])
          s.push(k++);
        else {
          int t = s.top();
          s.pop();
          ans = max(ans, sum[t]*(s.empty()?k:k-s.top()-1));
        }
      }
    }    
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<char> v1;
  v1.push_back('0');
  v1.push_back('1');
  v1.push_back('1');
  vector<char> v2;
  v2.push_back('0');
  v2.push_back('1');
  v2.push_back('1');
  vector<char> v3;
  v3.push_back('0');
  v3.push_back('0');
  v3.push_back('1');
  vector<vector<char> > v;
  v.push_back(v1);
  v.push_back(v2);
  Solution s;
  cout << s.maximalRectangle(v) << endl;
  return 0;
} 
