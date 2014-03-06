#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int ii = 0;
    int jj = height.size()-1;
    int ans = 0;
    while (ii < jj) {
      ans = max(ans, (jj-ii)*min(height[ii], height[jj]));
      if (height[ii] < height[jj]) {
        int pos = ii+1;
        while (pos < jj && height[pos] < height[ii])
          ++pos;
        ii = pos;
      } else {
        int pos = jj-1;
        while (pos >= ii && height[pos] < height[jj])
          --pos;
        jj = pos;
      }
    }
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  int data[] = {1, 2, 4, 3};
  vector<int> v(data, data+sizeof(data)/sizeof(int));
  Solution3 s;
  cout << s.maxArea(v) << endl;
  return 0;
} 
