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

// Determine whether a tree is sysmmetric.
// Solution: the same with determine two trees are same.
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    return isEqual(root->left, root->right); 
  }
  bool isEqual(TreeNode* p, TreeNode* q) {
    if (!p && q || !q && p)
      return false;
    if (!p && !q)
      return true;
    return p->val == q->val && isEqual(p->right, q->left) && isEqual(p->left, q->right);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* root = new TreeNode(-1);
  TreeNode* node = new TreeNode(-2);
  node->left = new TreeNode(-9);
  TreeNode* node2 = new TreeNode(-2);
  node2->right = new TreeNode(-9);
  root->left = node;
  root->right = node2;
  Solution s;
  cout << s.isSymmetric(root) << endl;
  return 0;
} 
