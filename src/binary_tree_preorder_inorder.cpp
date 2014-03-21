#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> preorder, inorder;
  int preorder_pos;
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    this->preorder = preorder;
    this->inorder = inorder;  
    preorder_pos = 0;
    return build(0, inorder.size()-1);
  }
  TreeNode* build(int in_i, int in_j) {
    if (in_i > in_j)
      return NULL;
    if (in_i == in_j)
      return new TreeNode(preorder[preorder_pos++]);
    int pos = in_i;
    while (inorder[pos] != preorder[preorder_pos])
      ++pos;
    TreeNode* root = new TreeNode(preorder[preorder_pos++]);
    root->left = build(in_i, pos-1);
    root->right = build(pos+1, in_j);
    return root;
  }
};

void dfs(TreeNode* root) {
  if (!root)
    return ;
  cout << (char)root->val << endl;
  dfs(root->left);
  dfs(root->right);
}
int main() {
  freopen("test.txt", "r", stdin);

  int data1[] = {'D', 'B', 'E', 'A', 'C'};
  int data2[] = {'A', 'B', 'D', 'E', 'C'};
  int len = sizeof(data1)/sizeof(int);
  vector<int> preorder(data2, data2+len);
  vector<int> inorder(data1, data1+len);

  Solution s;
  TreeNode* root = s.buildTree(preorder, inorder);
  dfs(root);
  return 0;
} 
