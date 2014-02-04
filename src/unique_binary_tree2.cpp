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

// Enum all different binary tree.
class Solution {
 public:
   vector<TreeNode *> generateTrees(int n) {
     return dfs(1, n);
   }

   // Range (left, right)
   vector<TreeNode*> dfs(int left, int right) {
     vector<TreeNode*> result;
     if (left > right) {
       result.push_back(NULL);
       return result;
     }
     vector<TreeNode*> left_subtree;
     vector<TreeNode*> right_subtree;
     for (int k = left; k <= right; ++k) {
       left_subtree = dfs(left, k-1);        
       right_subtree = dfs(k+1, right);
       for (int i = 0; i < left_subtree.size(); ++i) {
         for (int j = 0; j < right_subtree.size(); ++j) {
           TreeNode* root_node = new TreeNode(k);
           root_node->left = left_subtree[i];
           root_node->right = right_subtree[j];
           result.push_back(root_node);
         }
       }
     }
     return result;
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

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  vector<TreeNode*> result = s.generateTrees(3);
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); ++i) {
    s.print_in_order(result[i]);
    cout << endl;
  }
  return 0;
} 
