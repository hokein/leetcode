#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

//Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Determine whether a binary tree is balanced or not.
class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (!root)
      return true;
    int left = depth(root->left);
    int right = depth(root->right);
    if (abs(left-right) > 1)
      return false;
    return isBalanced(root->left) && isBalanced(root->right);
  }
  int depth(TreeNode* root) {
    if (!root)
      return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    return max(left, right)+1;
  } 
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(-2);
  node->left = new TreeNode(-9);
  node->right = new TreeNode(-9);
  node->left->left = new TreeNode(1);
  Solution s;
  cout << s.isBalanced(node) << endl;
  return 0;
} 
