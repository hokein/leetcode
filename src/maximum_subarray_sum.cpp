#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Maximum subarray sum problem
//
// We can use DP method to solve it in O(n).
// Also there is a divide and conquer solution, solve it in O(nlogn)

// Solution1: DP
//class Solution {
 //public:
  //int maxSubArray(int A[], int n) {
    //vector<int> dp(n, 0);     
    //dp[0] = A[0];
    //int ans = dp[0];
    //for (int i = 1; i < n; ++i) {
      //dp[i] = max(dp[i-1]+A[i], A[i]);
      //ans = max(ans, dp[i]);
    //}
    //return ans;
  //}
//};

// Solution2: Divide and conquer
//
// complexity: O(nlogn)
// O(n) = 2*O(n/2) + O(n)
class Solution {
 public:
  int maxSubArray(int A[], int n) {
    if (n == 1)
      return A[0];
    int mid = n/2;
    int sum = 0;
    int mid_left_max = 0;
    for (int i = mid-1; i >= 0; --i) {
      sum += A[i];
      mid_left_max = max(mid_left_max, sum);
    }
    sum = 0;
    int mid_right_max = 0;
    for (int i = mid+1; i < n; ++i) {
      sum += A[i];
      mid_right_max = max(mid_right_max, sum);
    }
    // mid point maximum value.
    int result = A[mid] + mid_left_max + mid_right_max;
    // left
    result = max(result, maxSubArray(A, mid));
    if (mid < n-1) // right if right have positions.
      result = max(result, maxSubArray(A+mid+1, n-(mid+1)));
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  //int a[] = {−2,1,−3,4,−1,2,1,−5,4};
  int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int len = 9;
  Solution s;
  cout << s.maxSubArray(a, len) << endl;
  return 0;
} 
