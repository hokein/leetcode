#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Using quick-sort partition
class Solution {
 public:
  void sortColors(int A[], int n) {
    int pos1 = partition(A, n, 0);
    partition(A+pos1, n-pos1, 1); 
  }
  int partition(int A[], int n, int pivot) {
    int i = 0;
    for (int j = 0; j < n; ++j)
      if (A[j] == pivot)
        swap(A[i++], A[j]);
    return i;
  }
};

// Use two-pointer method.
class Solution2 {
 public:
  void sortColors(int A[], int n) {
    int p1 = 0;
    int p3 = n-1;
    int p2 = 0;
    while (p2 <= p3) {
      while (p2 <= p3 && A[p2] == 1)
        ++p2;
      if (p2 > p3)
        break;
      if (A[p2] == 0) {
        swap(A[p1++], A[p2++]);
      } else if (A[p2] == 2)
        swap(A[p3--], A[p2]);
    }    
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {1,2,1,0,2,1,1,1,2,0,0,0,1,1,1,1,0,2,0,0,1,0,2,0,0,1,2,1,0};
  Solution s;
  s.sortColors(data, sizeof(data)/sizeof(int));
  for (int i = 0; i < sizeof(data)/sizeof(int); ++i)
    cout << data[i] << " ";
  cout << endl;
  return 0;
} 
