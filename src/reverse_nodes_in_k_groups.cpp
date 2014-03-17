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
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode dummpyNode(0);
    dummpyNode.next = head;
    ListNode* ed = &dummpyNode;    
    for (int i = 0; i < k && ed; ++i)
      ed = ed->next;
    ListNode* p = &dummpyNode;
    while (ed) {
      ListNode* prev = p->next;
      ListNode* cur = prev->next;
      // reverse [p->next, ed] list
      while (prev != ed) {
        ListNode* next_pos = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_pos;
      }
      // update head/trail elements.
      ListNode* last = p->next;
      p->next = prev;
      last->next = cur;

      // move to next end position. 
      p = ed = last;
      for (int i = 0; i < k && ed; ++i)
        ed = ed->next;
    } 
    return dummpyNode.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  ListNode* head;
  head = new ListNode(0);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next->next = new ListNode(6);
  Solution s;
  ListNode* ans = s.reverseKGroup(head, 8);
  while (ans) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  return 0;
} 
