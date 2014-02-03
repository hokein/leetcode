#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Remove a specified element in an array
//
// Solution: using two-scan method.
//
// A head pointer and a rear pointer.
class Solution {
 public:
  int removeElement(int A[], int n, int elem) {
    int fp = 0;
    int fr = n-1;
    while (fp <= fr) {
      // find a element swap place.
      while (fp < n-1) {
        if (A[fp] == elem)
          break;
        ++fp;
      }
      // find a candidate swap element.
      while (fr >= 0) {
        if (A[fr] != elem)
          break;
        --fr;
      }
      if (fp > fr)
        break;
      swap(A[fp], A[fr]);
      ++fp;
      --fr;
    }    
    return fp;
  }
};


int main() {
  freopen("test.txt", "r", stdin);

  int A[] = {6, 6, 6, 5, 6};
  int len = 1;
  Solution s;
  int remove_len = s.removeElement(A, len, 7);
  for (int i = 0; i < remove_len; ++i)
    cout << A[i] << " ";
  cout << endl;
  return 0;
} 
