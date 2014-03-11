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
  vector<int> searchRange(int A[], int n, int target) {
    vector<int> res;
    res.push_back(lower(A, n, target));  
    res.push_back(high(A, n, target));  
    return res;
  }
  int high(int A[], int n, int target) {
    int ans = -1;
    int l = 0, r = n-1;
    while (l <= r) {
      int mid = l + (r-l)/2;
      if (A[mid] == target) {
        ans = mid;
        l = mid+1;
      } else if (A[mid] < target) {
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  }
  int lower(int A[], int n, int target) {
    int ans = -1;
    int l = 0, r = n-1;
    while (l < r) {
      int mid = l + (r-l)/2;
      if (A[mid] == target) {
        r = mid;
      } else if (A[mid] < target) {
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return A[l] == target?l:-1;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {1, 1, 2, 2, 2};
  int len = sizeof(data)/sizeof(int);

  Solution s;
  vector<int> res = s.searchRange(data, 1, -1);
  cout << res[0] << " " << res[1] << endl;
  return 0;
} 
