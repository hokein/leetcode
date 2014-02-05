#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <stack>
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
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<TreeNode*> cur_layer;
    vector<vector<int> > result;   
    cur_layer.push_back(root); 
    int cnt = 0;
    while (!cur_layer.empty()) {
      vector<TreeNode*> next_layer;
      vector<int> v;
      while (!cur_layer.empty()) {
        TreeNode* fp = cur_layer.back();
        cur_layer.pop_back();
        if (!fp) continue;
        v.push_back(fp->val);
        if (cnt%2 == 1) {
          next_layer.push_back(fp->right);
          next_layer.push_back(fp->left);
        } else {
          next_layer.push_back(fp->left);
          next_layer.push_back(fp->right);
        }
      }
      if (!v.empty())
        result.push_back(v);
      cur_layer = next_layer;
      //if (cnt%2 == 1)
        //reverse(cur_layer.begin(), cur_layer.end());
      ++cnt;
    }
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  TreeNode* node = new TreeNode(3);
  node->left = new TreeNode(9);
  node->right = new TreeNode(20);
  node->right->left = new TreeNode(15);
  node->right->right = new TreeNode(7);
  Solution s;
  vector<vector<int> >ans = s.zigzagLevelOrder(node);
  for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
} 
