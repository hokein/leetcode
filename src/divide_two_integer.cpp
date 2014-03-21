#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Use minus to simulate divide.
// For faster, 2*divisor each time.
class Solution {
public:
  int divide(int dividend, int divisor) {
    int ans = 0;
    int negative = (dividend < 0) + (divisor < 0);
    // A special case:
    // dividend = INT_MIN, divisor = -1, the ans will overflow.
    // Need to long long here.
    ll a = abs((ll)dividend);
    ll b = abs((ll)divisor); 
    while (a >= b) {
      ll c = b;
      int i = 0;
      while (a >= c) {
        a -= c;
        ans += (1 << i);
        c <<= 1; // *2
        ++i;
      }
    }
    return negative == 1? -ans:ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.divide(-100, -3) << endl;
  return 0;
} 
