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
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    // leaf node
    if (!root->left && !root->right)
      return 1;
    int ret = -1;
    if (root->left)
      ret = minDepth(root->left);
    if (root->right) {
      int right = minDepth(root->right);
      ret = ret==-1?right:min(ret, right);
    }
    return ret+1;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(1);
  node->left = new TreeNode(2);
  node->left->right = new TreeNode(3);
  Solution s;
  cout << s.minDepth(node) << endl;
  return 0;
} 
