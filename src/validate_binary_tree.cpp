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
   static const int INF = 10000000;
   bool isValidBST(TreeNode *root) {
     if (!root)
       return true;
     int left = max_val(root->left);
     int right = min_val(root->right);  
     return left < root->val && root->val < right && isValidBST(root->left) && isValidBST(root->right);
   }
   int max_val(TreeNode* root) {
     if (!root)
       return -INF;
     return max(max(max_val(root->left), max_val(root->right)), root->val);
   }
   int min_val(TreeNode* root) {
     if (!root)
       return INF;
     return min(min(min_val(root->left), min_val(root->right)), root->val);
   }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(-2);
  node->left = new TreeNode(1);
  Solution s;
  cout << s.isValidBST(node) << endl;
  return 0;
} 
