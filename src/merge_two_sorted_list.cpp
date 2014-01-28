#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Merge two sorted lists in O(n)
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode virtual_node(0);
    ListNode* p = &virtual_node;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
        p = p->next;
        p->next = NULL;
      } else {
        p->next = l2;
        l2 = l2->next;
        p = p->next;
        p->next = NULL;
      }
    }
    // Append the rear of list.
    p->next = l2;
    if (l1)
      p->next = l1;
    return virtual_node.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {1, 1, 3, 4, 4};
  int b[] = {5, 6, 8};
  int len = 2;
  ListNode node(1), node2(2);
  ListNode* fr = &node;
  ListNode* fr2 = &node2;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr2->next = new ListNode(b[i]);
    fr = fr->next;
    fr2 = fr2->next;
  }
  Solution s;
  node.next = s.mergeTwoLists(node.next, node2.next);
  for (ListNode* p = node.next; p; p = p->next)
    cout << p->val << " ";
  cout << endl;
  return 0;
} 
