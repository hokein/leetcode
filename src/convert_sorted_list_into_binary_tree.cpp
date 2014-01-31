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
 
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Convert a sorted list into a balance binary tree.
//
// Solution: break the middle node.
class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head)           
      return NULL;
    ListNode virtual_node(0);
    virtual_node.next = head;
    // Get the middle point.
    ListNode* p1 = &virtual_node;
    ListNode* p2 = virtual_node.next;
    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next; 
    }
    ListNode* mid_point = p1->next;
    p1->next = NULL;
    ListNode* right_parts = mid_point->next;
    TreeNode* node = new TreeNode(mid_point->val);
    node->left = sortedListToBST(virtual_node.next);
    node->right = sortedListToBST(right_parts);
    return node;
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

  int a[] = {1, 3, 4};
  int len = 3;
  ListNode node(0);
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  Solution s;
  TreeNode* root = s.sortedListToBST(node.next);
  s.print_in_order(root);
  return 0;
} 

