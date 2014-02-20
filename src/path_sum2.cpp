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
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    if (!root)
      return vector<vector<int> >();
    if (!root->left && !root->right) {
      vector<vector<int> > ans;
      if (sum == root->val)
        ans.push_back(vector<int>(1, root->val));
      return ans;
    }
    bool valid = false;
    vector<vector<int> > left = pathSum(root->left, sum-root->val);
    vector<vector<int> > right = pathSum(root->right, sum-root->val);
    vector<vector<int> > ans;
    for (int i = 0; i < left.size(); ++i) {
      vector<int> path;
      path.push_back(root->val);
      for (int j = 0; j < left[i].size(); ++j)
        path.push_back(left[i][j]);
      ans.push_back(path);
    }
    for (int i = 0; i < right.size(); ++i) {
      vector<int> path;
      path.push_back(root->val);
      for (int j = 0; j < right[i].size(); ++j)
        path.push_back(right[i][j]);
      ans.push_back(path);
    }
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(2);
  node->left = new TreeNode(9);
  node->right = new TreeNode(9);
  node->left->left = new TreeNode(1);
  Solution s;
  vector<vector<int> > ans = s.pathSum(node, 11);
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
