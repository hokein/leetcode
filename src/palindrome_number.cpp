#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Determine whether a number is palindrome without extra place.
//
// An easy direct way:
//   convert a reversed number and check whether they are equal(consider overflow problem) 
// 
// To avoid overflow problem, we calculate the half part.
//  right  left
//       |
//      n/2 
// only check right ? left.
//
class Solution {
 public:
  bool isPalindrome(int x) {
    int result = 0;
    // A special case: 10, 100, but not 0.
    if (x > 0 && x%10 == 0)
      return false;
    while (x >= result) {
      // x may have odd numbers. skip 1.
      if (result == x || result == x/10)
        return true;
      result = 10*result + x%10; // get left part 
      x /= 10; // get right part 
    }     
    return false;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int num = -121;
  Solution s;
  cout << s.isPalindrome(num) << endl;
  return 0;
} 
