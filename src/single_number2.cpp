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
  int singleNumber(int A[], int n) {
    // records each digits appear times.
    int cnts[32] = {0};
    for (int i = 0; i < n; ++i) {
      int tmp = A[i];
      int j = 0;
      for (int j = 0; j < 32; ++j) {
        cnts[j] += (A[i]>>j)&1;
      }
    }
    int result = 0;
    for (int i = 31; i >= 0; --i)
      if (cnts[i]%3 == 0)
        result = result << 1; 
      else
        result = (result << 1) + 1;
    return result;
  }
};

class Solution2 {
 public:
  int singleNumber(int A[], int n) {
    int one, two, three;
    one = two = three = 0;
    for (int i = 0; i < n; ++i) {
      two |= (one&A[i]);
      one ^= A[i];
      three = ~(one&two);
      one &= three;
      two &= three;
    }
    return one;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int A[] = {-1, 2, 2, 2};
  Solution s;
  cout << s.singleNumber(A, sizeof(A)/sizeof(int)) << endl;
  return 0;
} 
