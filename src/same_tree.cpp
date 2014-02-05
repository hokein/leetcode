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

class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && q || !q && p) 
     return false;
    if (!p && !q) 
      return true;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(-2);
  node->left = new TreeNode(-9);
  TreeNode* node2 = new TreeNode(-2);
  node2->left = new TreeNode(-9);
  Solution s;
  cout << s.isSameTree(node, node2) << endl;
  return 0;
} 
