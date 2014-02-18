#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// a more elegant and simle code.
class Solution {
 public:
  int jump(int A[], int n) {
    int ans = 0;
    // last maximum distance can be reached.
    int last = 0;
    // cur maximum distance can be reached.
    int cur = 0;
    for (int i = 0; i < n; ++i) { 
      if (i > last) {
        last = cur;
        ++ans;
      }
      cur = max(cur, i+A[i]);
    }
    return ans;
  }
};

class Solution2 {
 public:
  int jump(int A[], int n) {
    if (n == 1)
      return 0;
    int steps = 0;
    for (int i = 0; i < n; ) {
      int next_pos = -1;
      int maxximum = 0;
      int j = i+1;
      // find next_pos which can jump longest.
      for (; j <= i+A[i] && j < n; ++j)
        if (j + A[j] > maxximum) {
          maxximum = j+A[j];
          next_pos = j;
        }
      if (j >= n) // next step can reach last index.
        return steps+1;
      if (maxximum >= n-1) // next next step can reach.
        return steps+2;
      ++steps;
      if (next_pos == -1)
        break;
      i = next_pos;
    }      
    return -1; // can not reach.
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {2, 3, 1, 1, 4};
  int n = 5;
  Solution s;
  cout << s.jump(data, n) << endl;
  return 0;
} 
