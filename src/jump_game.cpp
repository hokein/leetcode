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
  bool canJump(int A[], int n) {
    for (int i = 0; i < n; ) {
      int next_pos = -1;
      int maxximum = 0;
      // find next step can jump longest.
      for (int j = i+1; j <= i+A[i] && j < n; ++j)
        if (j + A[j] > maxximum) {
          maxximum = j+A[j];
          next_pos = j;
        }
      if (maxximum >= n-1) // can reach last index
        return true;
      if (next_pos == -1)
        break;
      i = j;
    }      
    return false;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {2, 3, 1, 1, 4};
  int n = 5;
  Solution s;
  cout << s.canJump() << endl;
  return 0;
} 
