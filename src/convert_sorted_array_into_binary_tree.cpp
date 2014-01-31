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
 
// Convert a sorted array into a balance binary tree.
//
// Solution: break the middle node.
class Solution {
 public:
  TreeNode *sortedArrayToBST(vector<int> &num) {
    return build(num.begin(), num.end());
  }
  // [st, ed)
  TreeNode *build(vector<int>::iterator st, vector<int>::iterator ed) {
    if (st == ed)
      return NULL;
    int steps = (ed-st)/2;
    TreeNode* new_node = new TreeNode(*(st+steps));
    new_node->left = build(st, st+steps);
    new_node->right = build(st+steps+1, ed); 
    return new_node;
  }
  void print_in_order(TreeNode* node) {
    if (!node)
      return;
    cout << node->val << " ";
    print_in_order(node->left);
    print_in_order(node->right);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {1, 2, 3, 4};
  int len = 4;
  vector<int> data(a, a+len);
  Solution s;
  TreeNode* root = s.sortedArrayToBST(data);
  s.print_in_order(root);
  return 0;
} 
