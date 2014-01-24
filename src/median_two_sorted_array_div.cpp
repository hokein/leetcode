#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// O(log(m+n)), Divide and conquer algorithm
//
// a[0 ... i ... m-1]
// b[0 ... j ... n-1]
//
// i = m/2, j = n/2
//
// 1) i + j + 1 < k
//     a[i] < b[j], median not in a[0:i] 
//     a[i] >= b[j], median not in b[0:j]
// 2) i + j + 1 >= k
//     a[i] > b[j], median not in a[i:m-1]
//     a[i] <= b[j], median not in b[j:n-1]
class Solution {
 public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int mid = (n+m+1)/2;
    if ((n+m)%2) {
      return find_nth_element(A, m, B, n, mid);
    } else {
      return (find_nth_element(A, m, B, n, mid) + find_nth_element(A, m, B, n, mid+1)) * 0.5;
    }
  }
  double find_nth_element(int A[], int m, int B[], int n, int k) {
    if (m <= 0)
      return B[k-1];
    if (n <= 0)
      return A[k-1];
    if (k <= 1)
      return min(A[0], B[0]);
    int i = m/2; 
    int j = n/2;
    if (i+j+1 < k) {
      if (A[i] < B[j])
        return find_nth_element(A+i+1, m-(i+1), B, n, k-(i+1));
      else // A[i] > B[j]
        return find_nth_element(A, m, B+j+1, n-(j+1), k-(j+1));
    } else { // i+j >= k
      if (A[i] < B[j])
        return find_nth_element(A, m, B, j, k);
      else
        return find_nth_element(A, i, B, n, k);
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

