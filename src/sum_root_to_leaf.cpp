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
  int sumNumbers(TreeNode *root) {
     if (!root)
       return 0;
     return rootSum(root, 0); 
  }
  int rootSum(TreeNode* root, int val) {
    if (!root->left && !root->right)
      return val*10+root->val;
    int sum = 0;
    if (root->left)
      sum = rootSum(root->left, val*10+root->val);
    if (root->right)
      sum += rootSum(root->right, val*10+root->val);
    return sum;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  Solution s;
  cout << s.sumNumbers(root) << endl;
  return 0;
} 
