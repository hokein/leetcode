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
  int sqrt(int x) {
    if (x == 0)
      return 0;
    int left = 1;
    int right = x;
    while (left <= right) {
      // Careful: mid*mid may cause overflow.
      int mid = left + (right-left)/2;
      if (mid == x/mid) {
        return mid;
      } else if (mid < x/mid) {
        left = mid+1;
      } else 
        right = mid-1;
    }    
    return right;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.sqrt(1) << endl;
  return 0;
} 
