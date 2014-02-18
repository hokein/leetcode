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
  double pow(double x, int n) {
    if (n < 0)
      return 1.0/__pow(x, -n);
    return __pow(x, n);
  }
  double __pow(double x, int n) {
    if (n == 0)
      return 1;
    if (n == 1)  
      return x;
    double half = pow(x, n/2);
    return half*half*(n%2?x:1);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.pow(2, 4) << endl;
  return 0;
} 
