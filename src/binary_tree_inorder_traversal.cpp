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

// Morris inorder traversal, O(1) space without stack.
//
// let cur pointer: root.
//
// 1. cur->left is null: print cur->val & cur = cur->right.
// 2. cur->left is not null:
//    find predecessor of cur node.
//    2.a) predecessor->right = null: not threaded, set thread.
//          predecssor->right = cur.
//          cur = cur->left.
//    2.b) predecessor->left != null: have been threaded, reset.
//          predecessor->right = null.
//          print cur->val
//          cur = cur->right.
//
// A detailed tutorial: http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    TreeNode* cur = root;
    vector<int> result;
    while (cur) {
      if (!cur->left) {
        result.push_back(cur->val);
        cur = cur->right; // move back to subtree root.
      } else {
        // Find a predecessor of node cur.
        TreeNode* prev = cur->left;
        while (prev->right && prev->right != cur)
          prev = prev->right;

        if (!prev->right) { // 2.a) null, set threaded at leaf's right son.
          prev->right = cur;
          cur = cur->left;
        } else { // 2.b) not null, reset to null.
          prev->right = NULL;
          result.push_back(cur->val); // subtree root val.
          cur = cur->right;
        }
      }
    }
    return result;
  }
};

// A elegant solution without visited flags. O(n) space, stack
// A detailed explaination from: http://leetcode.com/2010/04/binary-search-tree-in-order-traversal.html 
class Solution1 {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode*> s;
    vector<int> result;
    // maintain a current pointer
    TreeNode* cur = root;
    while (!s.empty() || cur) {
      if (cur) { // put all the left node of current in the stack.
        s.push(cur);
        cur = cur->left;
      } else {
        cur = s.top();
        s.pop();
        result.push_back(cur->val);
        cur = cur->right;
      }
    }
    return result;
  }
};

// A solution with visited flag
class Solution2 {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode*> s;
    stack<bool> left_vis;
    vector<int> inorder_seq;
    s.push(root); 
    left_vis.push(false);
    while (!s.empty()) {
      TreeNode* top = s.top();
      bool left_is_vis = left_vis.top();
      s.pop();
      left_vis.pop();
      if (!top) continue;
      if (!left_is_vis) { // top node left subtree is still unvisisted, keep top node in the stack
        s.push(top);
        left_vis.push(true);
        s.push(top->left);
        left_vis.push(false);
      } else {
        inorder_seq.push_back(top->val);
        s.push(top->right);
        left_vis.push(false);
      }
    }
    return inorder_seq; 
  }
};

// A recursive solution.
class Solution3 {
public:
  vector<int> inorder_seq;
  vector<int> inorderTraversal(TreeNode *root) {
    dfs(root);
    return inorder_seq;  
  }

  void dfs(TreeNode* root) {
    if (!root)
      return;
    dfs(root->left);
    inorder_seq.push_back(root->val);
    dfs(root->right);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(1);
  node->left = new TreeNode(2);
  node->right = new TreeNode(3);
  Solution s;
  vector<int> ans = s.inorderTraversal(node);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
} 

