#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// An easy question, before coding there are some good question to ask:
// 1. reverse an interger may leed to overflow.
// 2. what if 1000 after reverse? 0001
// 3. what if negative number?
class Solution {
 public:
  int reverse(int x) {
    int result = 0;
    while (x) {
      result = result*10 + x%10;
      x /= 10;
    }    
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int num = -121;
  Solution s;
  cout << s.reverse(num) << endl;
  return 0;
} 
