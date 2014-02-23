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
  const static int INF = 100000000; 
  int minimumTotal(vector<vector<int> > &triangle) {
    vector<int> prev(triangle.size(), 0);
    vector<int> cur(triangle.size(), 0);
    for (int i = 0; i < triangle.size(); ++i) {
      cur[0] = prev[0] + triangle[i][0];
      for (int j = 1; j < triangle[i].size()-1; ++j) {
        cur[j] = min(prev[j], prev[j-1]) + triangle[i][j];
      }
      if (triangle[i].size() > 1)
        cur[triangle[i].size()-1] = prev[triangle[i].size()-1-1] + triangle[i].back();
      prev = cur;
    }
    int mini = INF;
    for (int i = 0; i < cur.size(); ++i) {
      mini = min(cur[i], mini);
    }
    return mini;
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  vector<vector<int> > triangle;

  vector<int> v1;
  v1.push_back(1);
  vector<int> v2;
  v2.push_back(1);
  v2.push_back(2);
  triangle.push_back(v1);
  triangle.push_back(v2);
  Solution s;
  cout << s.minimumTotal(triangle) << endl;
  return 0;
} 
