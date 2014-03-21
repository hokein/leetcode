#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
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

class Solution {
 public:
  vector<int> postorder, inorder;
  int postorder_pos;
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    this->postorder = postorder;
    this->inorder = inorder;  
    postorder_pos = postorder.size()-1;
    return build(0, inorder.size()-1);
  }
  TreeNode* build(int in_i, int in_j) {
    if (in_i > in_j)
      return NULL;
    if (in_i == in_j)
      return new TreeNode(postorder[postorder_pos--]);
    int pos = in_i;
    while (inorder[pos] != postorder[postorder_pos])
      ++pos;
    TreeNode* root = new TreeNode(postorder[postorder_pos--]);
    root->right = build(pos+1, in_j);
    root->left = build(in_i, pos-1);
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
  int data2[] = {'D', 'E', 'B', 'C', 'A'};
  int len = sizeof(data1)/sizeof(int);
  vector<int> postorder(data2, data2+len);
  vector<int> inorder(data1, data1+len);

  Solution s;
  TreeNode* root = s.buildTree(inorder, postorder);
  dfs(root);
  return 0;
} 

