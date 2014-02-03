#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
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
  vector<vector<int> > levelOrder(TreeNode *root) {
    queue<TreeNode*> cur_layer;
    vector<vector<int> > result;   
    cur_layer.push(root); 
    while (!cur_layer.empty()) {
      queue<TreeNode*> next_layer;
      vector<int> v;
      while (!cur_layer.empty()) {
        TreeNode* fp = cur_layer.front();
        cur_layer.pop();
        if (!fp) continue;
        v.push_back(fp->val);
        next_layer.push(fp->left);
        next_layer.push(fp->right);
      }
      if (!v.empty())
        result.push_back(v);
      cur_layer = next_layer;
    }
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(1);
  node->left = new TreeNode(2);
  node->right = new TreeNode(3);
  Solution s;
  vector<vector<int> >ans = s.levelOrder(node);
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
