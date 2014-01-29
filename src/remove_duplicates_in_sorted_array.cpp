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
  int removeDuplicates(int A[], int n) {
    if (n == 0)
      return 0;
    int last_pos = 0;      
    for (int i = 1; i < n; ++i)
      if (A[last_pos] < A[i])
        A[++last_pos] = A[i];
    return last_pos+1;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int A[] = {1, 1, 1, 4, 5};
  int len = 5;
  Solution s;
  int size = s.removeDuplicates(A, len);
  cout << size << endl;
  for (int i = 0; i < size; ++i)
    cout << A[i] << " ";
  cout << endl;
  return 0;
} 
