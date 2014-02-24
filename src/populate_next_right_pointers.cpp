#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// Recursive solution: O(h) space.
class Solution1 {
 public:
  void connect(TreeLinkNode *root) {
    if (!root)
      return ;
    TreeLinkNode dummy_node(-1);
    TreeLinkNode* cur = root;
    TreeLinkNode* next = &dummy_node;
    // connect next layer.
    for ( ; cur; cur = cur->next) {
      if (cur->left) {
        next->next = cur->left;
        next = next->next;
      }
      if (cur->right) {
        next->next = cur->right;
        next = next->next;
      }
    }
    connect(dummy_node.next);
  }
};

// BFS, O(n) space. 
class Solution2 {
 public:
  void connect(TreeLinkNode *root) {
    if (!root)
      return ;
    vector<TreeLinkNode*> cur;
    cur.push_back(root);
    while (!cur.empty()) {
      vector<TreeLinkNode*> prev; 
      for (int i = 0; i < cur.size()-1; ++i) {
        cur[i]->next = cur[i+1];
      }
      cur[cur.size()-1]->next = NULL;
      for (int i = 0; i < cur.size(); ++i) {
        if (cur[i]->left)
          prev.push_back(cur[i]->left);
        if (cur[i]->right)
          prev.push_back(cur[i]->right);
      }
      cur = prev;
    }  
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  return 0;
} 
