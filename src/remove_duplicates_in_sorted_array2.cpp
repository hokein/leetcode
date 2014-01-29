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
    int last_pos = -1;      
    for (int i = 0; i < n; ) {
      A[++last_pos] = A[i];
      // scan all equal elements.
      int j = i+1;
      while (j < n && A[j] == A[i]) 
        ++j;
      if (j != i+1)
        A[++last_pos] = A[i];
      i = j;
    }
    return last_pos+1;
  }
};

// Another solution, more efficient but more complicate
// each time move to steps, and check.
//class Solution {
 //public:
  //int removeDuplicates(int A[], int n) {
    //int last_pos = -1;      
    //for (int i = 1; i < n; i+=2) {
      //if (last_pos >= 0 && A[i] == A[last_pos] && A[i] == A[last_pos-1])
        //continue;
      //if (last_pos == -1) {
        //A[++last_pos] = A[i-1];
        //A[++last_pos] = A[i];
        //continue;
      //}
      //if (A[i-1] != A[last_pos] || (A[i-1] == A[last_pos] && A[i-1] != A[last_pos-1]))
        //A[++last_pos] = A[i-1];
      //if (A[i] != A[last_pos] || (A[i] == A[last_pos] && A[i] != A[last_pos-1]))
        //A[++last_pos] = A[i];
    //}
    //if (n%2) {
      //if (last_pos < 1 || (A[last_pos] != A[n-1] 
                           //|| (A[last_pos] == A[n-1] && A[last_pos-1] != A[n-1])))
        //A[++last_pos] = A[n-1];
    //}
      
    //return last_pos+1;
  //}
//};

int main() {
  freopen("test.txt", "r", stdin);

  int A[] = {0, 1, 1, 1, 4, 5};
  int len = 6;
  Solution s;
  int size = s.removeDuplicates(A, len);
  cout << size << endl;
  for (int i = 0; i < size; ++i)
    cout << A[i] << " ";
  cout << endl;
  return 0;
} 

