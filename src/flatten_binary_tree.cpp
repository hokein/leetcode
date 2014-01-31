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

// Flatten a balance weighted binary tree.
//
// Make a list.
//   2 
//  / \
// 1   3
//
// =>  1
//      \
//       2
//        \
//         3
// 
// One solution with O(n) extra space.
//
// In_order the binary tree, and record the sequence, and rebuild the tree.
//
// A more elegant in-place solution is below:
class Solution {
 public:
  void flatten(TreeNode *root) {
    while (root) {
      if (root->left) { // has left subtree
        TreeNode* p = root->left; // subtree root
        while (p->right) p = p->right; // reach subtree right deepest node.
        p->right = root->right; // concatenate root tree right-subtree
        // move the left tree to right, since root->right is empty now.
        root->right = root->left;
        root->left = NULL;
      }
      root = root->right; // next steps.
    }
  }
  void print_in_order(TreeNode* node) {
    if (!node) {
      cout << "# ";
      return;
    }
    cout << node->val << " ";
    print_in_order(node->left);
    print_in_order(node->right);
  }
};

//class Solution {
 //public:
  //// record the in order sequence.
  //vector<TreeNode*> seq;
  //void flatten(TreeNode *root) {
    //if (!root)
      //return;
    //in_order_traversal(root);
    //*root = *seq[0];
    //TreeNode* p = root;
    //for (int i = 1; i < seq.size(); ++i) {
      //p->right = seq[i];
      //p = p->right;
    //}
  //}
  //void in_order_traversal(TreeNode *root) {
    //if (!root)
      //return;
    //seq.push_back(new TreeNode(root->val));
    //in_order_traversal(root->left);
    //in_order_traversal(root->right); 
    //delete(root);
  //}

  //void print_in_order(TreeNode* node) {
    //if (!node) {
      //cout << "# ";
      //return;
    //}
    //cout << node->val << " ";
    //print_in_order(node->left);
    //print_in_order(node->right);
  //}
//};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(1);
  node->left = new TreeNode(2);
  Solution s;
  s.flatten(node);
  s.print_in_order(node);
  cout << endl;
  return 0;
} 
