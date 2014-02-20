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

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root)
      return false;
    if (!root->left && !root->right)
      return sum == root->val;
    bool valid = false;
    if (root->left)
      valid = hasPathSum(root->left, sum-root->val);
    if (root->right) 
      valid |=  hasPathSum(root->right, sum-root->val);
    return valid;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(2);
  node->left = new TreeNode(9);
  //node->right = new TreeNode(9);
  //node->left->left = new TreeNode(1);
  Solution s;
  cout << s.hasPathSum(node, 2) << endl;
  return 0;
} 
