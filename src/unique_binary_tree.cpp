#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Calculate the number of unique binary trees made of n nodes.
// then same as the number of a n-elements stack unique pop sequence.
//
// Catalan number: C(2n, n)/(n+1) = 2n*...*(n+1)/(n+1)!
// The recursion formula: Cantalan(n) = C(2n, n)-C(2n, n+1)
// 
// Proof:
//
// consider a 2n elements sequence, 0 means pop, 1 means push.
// Cantalan number is the the sequence[0,..., i], nums(0) <= nums(1), make sure
// the stack always have element to pop.
//
// The total sequence is : C(2n, n), select n element from 2n elements.
// Than calculate the invalid sequence:
//
// It must exist a place 2m+1, which there are m+1 0s, m 1s, so there are 2n-(m+1) 0s, 
// 2n-(m) 1s from [2m+2, ..., 2n], nums(1)-nums(0) = 1; we swap the 1 and 0.
// Than there are (n+1) 0s, (n-1) 1s.
//
// So Catalan(n) = C(2n, n) - C(2n, n+1)
//
// A graphic tutorial: http://blog.sina.com.cn/s/blog_6917f47301010cno.html 
class Solution {
 public:
  int numTrees(int n) {
    long long permutation_n = 1;
    long long permutation_2n = 1;
    for (int i = 2*n; i > n+1; --i)    
      permutation_2n *= i;
    for (int i = 2; i <= n; ++i)
      permutation_n *= i;
    // this may have a overflow problem.
    return permutation_2n/permutation_n;
  }
};

// An optimal DP Solution
// dp[n]: the numbers of binary tree with n nodes.
// dp[n] = sum(dp[i]*dp[n-i-1]), i = 0,...,n-1
//
// left subtrees number * right subtrees number
//
// Equal to catalan number
class Solution-DP {
 public:
  int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j)
        dp[i] += dp[j]*dp[i-j-1];
    }
    return dp[n];
  }
};
int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.numTrees(3) << endl;
  return 0;
} 
