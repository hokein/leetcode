#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Right Rotate the given list k steps.
// Solution the same as remove last nth list elements.
//
// Two slow&fast pointers.
//
//  ... a[n-k] a[n-k+1]  ...  a[n]
//       |         |           | 
//      slow    new Head      fast
class Solution {
 public:
  int lenList(ListNode *head) {
    ListNode *p = head;
    int len = 0;
    while (p) {
      ++len;
      p = p->next;
    }
    return len;
  }
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
      return head;
    int move_steps = k%lenList(head); 
    ListNode virtual_node(0);
    virtual_node.next = head;
    ListNode* fast = &virtual_node; 
    while (move_steps--) {
      fast = fast->next;
    }
    ListNode* slow = &virtual_node;
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    fast->next = virtual_node.next;
    virtual_node.next = slow->next;
    slow->next = NULL;
    return virtual_node.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {2, 3, 4, 1};
  int len = 4;
  ListNode node(1);
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  Solution s;
  node.next = s.rotateRight(node.next, 1);
  for (ListNode* p = node.next; p; p = p->next)
    cout << p->val << " ";
  cout << endl;
  return 0;
} 
