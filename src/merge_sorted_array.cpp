#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Merge two sorted array in place.
//
// Solution: merge from backword, not forward!
// 
// From backward, we can avoid to override the value of array A.
class Solution {
 public:
  void merge(int A[], int m, int B[], int n) {
    int pos1 = m-1, pos2 = n-1;      
    int pos = m+n-1;
    while (pos1 >= 0 || pos2 >= 0) {
      if (pos2 < 0 || (pos1 >= 0 && A[pos1] > B[pos2]))
        A[pos--] = A[pos1--];
      else
        A[pos--] = B[pos2--];
    }
  }
};

// Merge in place, but more complicate, will distroy array B.
//class Solution {
 //public:
  //void merge(int A[], int m, int B[], int n) {
    //int pos1 = 0, pos2 = 0;      
    //int pos = 0;
    //for (int i = 0; i < n; ++i)
      //A[m+i] = B[i];
    //while (pos1 < m || pos2 < n) {
      //int *merged_array = B;
      //int index = pos;
      //if (pos >= n) {
        //merged_array = A;
        //index -= n;
      //}
      //if (pos2 >= n || (pos1 < m && A[pos1] < A[pos2+m]))
        //merged_array[index] = A[pos1++];
      //else {
        //merged_array[index] = A[pos2+m];
        //++pos2;
      //}
      //++pos;
    //}
    //for (int i = 0; i < m; ++i)
      //A[m+n-1-i] = A[m-1-i];
    //for (int i = 0; i < n; ++i)
      //A[i] = B[i];
  //}
//};

int main() {
  freopen("test.txt", "r", stdin);
  
  int A[] = {4, 5, 6, 0, 0, 0};
  int B[] = {1, 2, 3};
  int len = 3;
  Solution s;
  s.merge(A, len, B, 0);
  for (int i = 0; i < len*2; ++i)
    cout << A[i] << " ";
  cout << endl;

  return 0;
}
