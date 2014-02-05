#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Calculate the maximum path sum in the tree. The start/end nodes can be any where of the tree.
//
// Solution: Divide and conquer.
//
// The maximum path value of a root T binary Tree:
//
//  1. the left subtree of T.
//  2. the right subtree of T.
//  3. left subtree + root.
//  4. right subtree + root. 
//  5. left subtree + root + right subtree.
class Solution {
 public:
  int maxx;
  const static int INF = 10000000;
  Solution() {
    maxx = -INF;
  }
  int maxPathSum(TreeNode *root) {
    solve(root);
    return maxx;    
  }
  int solve(TreeNode *root) {
    if (!root)
      return -INF;
    int left_max = solve(root->left);
    int right_max = solve(root->right);
    maxx = max(maxx, left_max); // only left
    maxx = max(maxx, right_max); // only right
    maxx = max(maxx, root->val); // only root
    maxx = max(maxx, left_max+root->val); // left+root
    maxx = max(maxx, right_max+root->val); // right+root
    maxx = max(maxx, left_max+right_max+root->val); // left+root+right.
    // return the largest sum path value start from root node.
    // maybe only the root node.
    return max(max(left_max, right_max), 0)+root->val;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(-2);
  node->left = new TreeNode(-9);
  Solution s;
  cout << s.maxPathSum(node) << endl;
  return 0;
} 
