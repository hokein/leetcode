#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Binary search in unique rotated array.
//
// First determine [l, r] is in rotated array or one sorted array.
//
// Second, detemine target on left/right parts.
//
// Lastly, detemine mid on target's left/right parts.
class Solution {
 public:
  int search(int A[], int n, int target) {
    int l = 0, r = n-1;
    // search in [l, r] range.
    while (l <= r) {
      int mid = l + (r-l)/2;
      if (A[mid] == target)
        return mid;
      if (A[l] < A[r]) {
        if (A[mid] < target)
          l = mid+1;
        else
          r = mid-1;
      } else {
        if (target >= A[l]) {
          if (A[mid] > target || A[mid] <= A[r])
            r = mid - 1;
          else
            l = mid + 1;
        } else {
          if (A[mid] < target || A[mid] >= A[l])
            l = mid + 1;
          else
            r = mid - 1;
        }
      }
    }   
    return -1;
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  int A[] = {4, 5, 0, 1, 2};
  int len = 5;
  Solution s;
  for (int i = 0; i < len; ++i) {
    int size = s.search(A, len, A[i]);
    cout << size << endl;
  }
  return 0;
} 
