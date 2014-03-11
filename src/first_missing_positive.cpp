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
  int firstMissingPositive(int A[], int n) {
    for (int i = 0; i < n; ++i) {
      // put A[i] to the correct position A[A[i]-1].
      // It will be O(n) here.
      while (A[i] != i+1) {
        // ignore out range elements and correct elements.
        if (A[i] < 0 || A[i] > n || A[i] == i+1)
          break;
        swap(A[i], A[A[i]-1]);
      }
    } 

    for (int i = 0; i < n; ++i)
      if (A[i] != i+1)
        return i+1;
    return n+1;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {3, 2, 10};
  int n = sizeof(data)/sizeof(int);

  Solution s;
  cout << s.firstMissingPositive(data, n) << endl;
  return 0;
} 
