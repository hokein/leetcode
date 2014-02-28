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
    int result = 0;
    for (int i = 0; i < n; ++i) {
      result ^= A[i];
    }   
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  return 0;
} 
