#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
};

// Merge sort
class Solution {
 public:
  ListNode *sortList(ListNode *head) {
    // 0 or 1 element.
    if (!head || !head->next)
      return head;
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    // p1 skip 1 step.
    // p2 skip 2 steps.
    // get middle element.
    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }    
    ListNode* right_half = p1->next;
    p1->next = NULL; // break the list.
    ListNode* left = sortList(head);
    ListNode* right = sortList(right_half);
    ListNode virtual_node(0);
    ListNode* fr = &virtual_node; 
    while (left && right) {
      if (left->val < right->val) {
        fr->next = left;
        left = left->next;
        fr = fr->next;
        fr->next = NULL;
      } else {
        fr->next = right;
        right = right->next;
        fr = fr->next;
        fr->next = NULL;
      }
    }
    fr->next = right;
    if (left)
      fr->next = left;
    return virtual_node.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {4, 3, 2, 1};
  int len = 2;
  ListNode node;
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  Solution s;
  node.next = s.sortList(node.next);
  for (ListNode* p = node.next; p; p = p->next)
    cout << p->val << " ";
  ListNode* p = node.next;
  while (p) {
    ListNode* tmp = p->next;
    delete p;
    p = tmp;
  }
  cout << endl;

  return 0;
} 
