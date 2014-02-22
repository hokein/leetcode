#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Implement atoi, consider the following cases:
//
// 1. return 0, if data is not valid.
// 2. Only allow at most one '-'/'+' operator sign.
// 3. overflow data, will return MAX_INT/MIN_INT.
// 4. return the maximum value can performed until miss invalid character("111b" return b)
class Solution {
 public:
  int atoi(const char *str) {
    bool is_negative = false;
    int i = 0;
    // skip prefix blank space.
    while (str[i] && str[i] == ' ') {
      ++i;
    }
    if (str[i] == '-' || str[i] == '+') {
      is_negative = str[i] == '-';
      ++i;
    } 
    int nums = 0;
    while (str[i] >= '0' && str[i] <= '9') {
      if (is_negative) {
        int tmp = 10*nums - (str[i++]-'0');
        if (tmp/10 != nums)
          return -2147483648; // INT_MIN
        nums = tmp;
      } else {
        int tmp = 10*nums + (str[i++]-'0');
        if (tmp/10 != nums)
          return 2147483647; // INT_MAX
        nums = tmp;
      }
    }
    return nums;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a = 1052254545;
  Solution s;
  cout << s.atoi("b1") << endl;
  cout << s.atoi("+ 1") << endl;
  cout << s.atoi("- 1") << endl;
  cout << s.atoi("10522545459") << endl;
  cout << s.atoi("2147483647") << endl;
  cout << s.atoi("2147483648") << endl;
  cout << s.atoi("-2147483649") << endl;
  cout << s.atoi("-2147483648") << endl;
  return 0;
} 
