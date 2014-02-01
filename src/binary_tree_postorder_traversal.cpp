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

// A more elegant solution, without visited flag.
//
// A preorder-based solution with a stack. 
//
// preorder sequence:
//   root, left, right.
// postorder sequence:
//   left, right, root.
//
// If we change a little preorder order:
//   root, right, left.
// 
// We can see that reverse(root, right, left) = (left, right, root).
//
// Just record the preorder sequence and reverse it.
// A more detailed explaination from: http://leetcode.com/2010/10/binary-tree-post-order-traversal.html 
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode*> s;
    vector<int> pre_order;
    s.push(root); 
    while (!s.empty()) {
      TreeNode* top = s.top();
      s.pop();
      if (!top) continue;
      pre_order.push_back(top->val);
      // Note: not the same order with preorder.
      s.push(top->left);
      s.push(top->right);
    }
    // reverse.
    return vector<int>(pre_order.rbegin(), pre_order.rend());
  }
};

// A solution with visited flag, record left&right subtree is visited or not.
// Emulate recursive solution.
class Solution2 {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode*> s;
    stack<bool> left_vis;
    stack<bool> right_vis;
    vector<int> postorder_seq;
    s.push(root); 
    left_vis.push(false);
    right_vis.push(false);
    while (!s.empty()) {
      TreeNode* top = s.top();
      bool left_is_vis = left_vis.top();
      bool right_is_vis = right_vis.top();
      s.pop();
      left_vis.pop();
      right_vis.pop();
      if (!top) continue;
      // top node left&right subtree is still unvisisted, keep top node in the stack
      if (!left_is_vis) {
        s.push(top);
        left_vis.push(true);
        right_vis.push(false);
        s.push(top->left);
        left_vis.push(false);
        right_vis.push(false);
      } else if (left_is_vis && !right_is_vis){ // left tree is visited, right tree not.
        s.push(top);
        left_vis.push(true);
        right_vis.push(true);
        s.push(top->right);
        left_vis.push(false);
        right_vis.push(false);
      } else { // both left&right tree is visited.
        postorder_seq.push_back(top->val);
      }
    }
    return postorder_seq; 
  }
};

//// A recursive solution.
class Solution3 {
public:
  vector<int> postorder_seq;
  vector<int> postorderTraversal(TreeNode *root) {
    dfs(root);
    return postorder_seq;  
  }

  void dfs(TreeNode* root) {
    if (!root)
      return;
    dfs(root->left);
    dfs(root->right);
    postorder_seq.push_back(root->val);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(1);
  node->left = new TreeNode(2);
  node->right = new TreeNode(3);
  Solution s;
  vector<int> ans = s.postorderTraversal(node);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
} 
