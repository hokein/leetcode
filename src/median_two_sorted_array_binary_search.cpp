#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// O(logm*logn), using binary search.
// Foreach element a[i], binnary search position j in b
// check i+j+1 whether equal to n. 
// Should consider equal elements.
class Solution {
 public:
  int find_nth_element_wrapper(int nth, int A[], int m, int B[], int n) {
    // first find array a, if not find, change array a and b.
    int ans = find_nth_element(nth, A, m, B, n);
    if (ans == -1)
      ans = find_nth_element(nth, B, n, A, m);
    return ans;
  }
  int find_nth_element(int nth, int A[], int m, int B[], int n) {
    int l = 0, r = m;
    while (l < r) {
      int mid = l + (r-l)/2;
      // for equality elements.
      int lower_j = lower_bound(B, B+n, A[mid])-B;
      int upper_j = upper_bound(B, B+n, A[mid])-B;
      if (lower_j+mid+1 <= nth && upper_j+mid+1 >= nth)
        return A[mid];
      else if (lower_j + mid < nth) {
        l = mid+1; 
      } else {
        r = mid;
      }
    }
    return -1;
  }
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int mid = (1+n+m)/2;
    if ((n+m)%2) {
      return find_nth_element_wrapper(mid, A, m, B, n);
    } else {
      double ans = find_nth_element_wrapper(mid, A, m, B, n) + find_nth_element_wrapper(mid+1, A, m, B, n);
      return ans*0.5;
    }
  }
};


int main() {
  freopen("test.txt", "r", stdin);

  int A[] = {1, 1, 10, 100};
  int B[] = {1, 6, 7, 10};
  int m = 1, n = 1;
  Solution s;
  cout << s.findMedianSortedArrays(A, m, B, n) << endl;
  return 0;
} 
