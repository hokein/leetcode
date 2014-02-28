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
  int searchInsert(int A[], int n, int target) {
    int left = 0;
    int right = n-1;    

    while (left <= right) {
      int mid = left + (right-left)/2;
      if (A[mid] == target)
        return mid;
      else if (A[mid] < target)
        left = mid+1;
      else
        right = mid-1;
    }
    return left;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int A[] = {1, 3, 5, 6};
  Solution s;
  cout << s.searchInsert(A, sizeof(A)/sizeof(int), 4) << endl;
  return 0;
} 
