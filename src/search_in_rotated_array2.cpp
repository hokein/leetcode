#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Binary search in dupulicates rotated array.
//
// Solution: the same of seaching in unique rotated array except one difference.
// 
// should be considered the equality of a[l] = a[r], if a[mid] = a[r], 
// maybe mid at left part or right part, should be checked both.(Using recursive method for convenience)
//
// complexity: O(logn) may be larger than unique rotated array.
// O(n) = 2*(n/2) + O(1)
class Solution {
 public:
  bool search(int A[], int n, int target) {
    if (n == 0)
      return false;
    int l = 0, r = n-1;
    // search in [l, r] range.
    while (l <= r) {
      int mid = l + (r-l)/2;
      if (A[mid] == target)
        return true;
      if (A[l] < A[r]) {
        if (A[mid] < target)
          l = mid+1;
        else
          r = mid-1;
      } else {
        if (target >= A[l]) { // target at left parts
          if (A[mid] > target || A[mid] < A[r])
            return search(A, mid, target);
          else if (A[mid] == A[r]) // we can not determine mid at which parts, should be checked both.
            return search(A, mid, target) || search(A+mid+1, n-(mid+1), target);
          else
            return search(A+mid+1, n-(mid+1), target);
        } else { // target at right parts
          if (A[mid] < target || A[mid] > A[l]) // mid at target left
            return search(A+mid+1, n-(mid+1), target);
          else if (A[mid] == A[l])  // we can not determine mid at which parts, the same above.
            return search(A+mid+1, n-(mid+1), target) || search(A, mid, target);
          else // mid at target right
            return search(A, mid, target);
        }
      }
    }   
    return false;
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  int A[] = {3, 1, 1, 3, 1, 1, 1};
  int len = 3;
  Solution s;
  for (int i = 0; i < len; ++i) {
    int size = s.search(A, len, A[i]);
    cout << size << endl;
  }
  return 0;
} 

