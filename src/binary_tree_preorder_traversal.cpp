#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <stack>
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

// Morris preorder traversal, O(1) space
// the same as inorder traversal.
// 1. cur->left is null: print cur->val & cur = cur->right.
// 2. cur->left is not null:
//    find predecessor of cur node.
//    2.a) predecessor->right = null: not threaded, set thread.
//          print cur->val
//          predecssor->right = cur.
//          cur = cur->left.
//    2.b) predecessor->left != null: have been threaded, reset.
//          predecessor->right = null.
//          cur = cur->right.
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    TreeNode* cur = root;
    vector<int> result;
    while (cur) {
      if (!cur->left) {
        result.push_back(cur->val);
        cur = cur->right;
      } else {
        TreeNode* prev = cur->left;
        while (prev->right && prev->right != cur)
          prev = prev->right;
        if (!prev->right) {
          result.push_back(cur->val);
          prev->right = cur;
          cur = cur->left;
        } else {
          prev->right = NULL;
          cur = cur->right;
        }
      }
    }
    return result;
  }
};

// An iterative solution: O(n) space.
class Solution1 {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode*> s;
    vector<int> preorder_seq;
    s.push(root); 
    while (!s.empty()) {
      TreeNode* top = s.top();
      s.pop();
      if (!top) continue;
      preorder_seq.push_back(top->val);
      // Note: careful with the order.
      //
      // The stack trace:
      // top ->     left
      //            right
      // bottom ->  node
      s.push(top->right);
      s.push(top->left);
    }
    return preorder_seq; 
  }
};

// A recursive solution.
class Solution2 {
public:
  vector<int> preorder_seq;
  vector<int> preorderTraversal(TreeNode *root) {
    dfs(root);
    return preorder_seq;  
  }

  void dfs(TreeNode* root) {
    if (!root)
      return;
    preorder_seq.push_back(root->val);
    dfs(root->left);
    dfs(root->right);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(1);
  node->left = new TreeNode(2);
  node->right = new TreeNode(3);
  Solution s;
  vector<int> ans = s.preorderTraversal(node);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
} 
