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

// Morris inorder traversal variation, O(n) space, complexity O(n)
class Solution {
 public:
  TreeNode* f1, *f2;
  void recoverTree(TreeNode *root) {
    f1 = f2 = NULL;
    TreeNode* prev = NULL;
    TreeNode* cur = root;   
    while(cur) {
      if (!cur->left) {
        detect(prev, cur);
        prev = cur;
        cur = cur->right;
      } else {
        TreeNode* tmp = cur->left;
        while (tmp->right && tmp->right != cur)
          tmp = tmp->right;
        if (!tmp->right) {
          tmp->right = cur;
          cur = cur->left;
        } else {
          detect(prev, cur);
          tmp->right = NULL;
          prev = cur;
          cur = cur->right;
        }
      }
    }
    swap(f1->val, f2->val);
  }

  void detect(TreeNode* prev, TreeNode* cur) {
    if (prev && cur && prev->val > cur->val) {
      if (!f1) // first time (big, small), choose big, second time (big, small) choose small.
        f1 = prev;
      f2 = cur;
    }
  }
};

// O(n) space.
class Solution1 {
 public:
  vector<TreeNode*> in_order;
  void recoverTree(TreeNode *root) {
    dfs(root);
    for (int i = 1; i < in_order.size(); ++i)
      if (in_order[i]->val < in_order[i-1]->val) {
        for (int j = i+1; j < in_order.size(); ++j)
          if (in_order[j]->val < in_order[j-1]->val) {
            swap(in_order[i-1]->val, in_order[j]->val);
            return;  
          }
        swap(in_order[i]->val, in_order[i-1]->val);
        return;
      }
  }
  void dfs(TreeNode* root) {
    if (!root)
      return;
    dfs(root->left);
    in_order.push_back(root);
    dfs(root->right);
  }
  void print(TreeNode* root) {
    if (!root)
      return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(2);
  node->right = new TreeNode(3);
  node->right->left = new TreeNode(1);
  Solution s;
  Solution1 s1;
  s.recoverTree(node);
  s1.print(node);
  cout << endl;
  return 0;
} 
