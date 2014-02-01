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

// An iterative solution.
class Solution {
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
