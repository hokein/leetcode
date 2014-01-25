#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
};

// O(n) + O(1) space
//
// a1,   a2,   a3, ..., an
// a1,   a2,   a3, ..., ak
// ak+1, ak+2, ak+3 , ..., a2k
//
// a1 ak+1, a2, ak+2, ..., ak+a2k
// 1. Break the list into two equal parts.
// 2. Reverse the second parts
// 3. Merge
class Solution {
 public:
  ListNode* reverse(ListNode* head) {
    if (!head)
      return head;
    ListNode* pre = head; 
    ListNode* cur = head->next;
    pre->next = NULL;
    while (cur) {
      ListNode* next_pos = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next_pos;
    }
    return pre;
  } 
  void reorderList(ListNode *head) {
    if (!head || !head->next)
      return ;
    ListNode* p1, *p2;
    p1 = p2 = head;
    p2 = head->next;
    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }
    // break list into two half
    ListNode* right_half_head = p1->next;
    p1->next = NULL;
    right_half_head = reverse(right_half_head);

    p1 = head;
    p2 = right_half_head;
    while (p1 && p2) {
      ListNode* p1_next = p1->next;
      ListNode* p2_next = p2->next;
      p1->next = p2;
      if (p1_next)
        p2->next = p1_next;
      p1 = p1_next;
      p2 = p2_next;
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {2, 3, 4, 1};
  int len = 4;
  ListNode node;
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  Solution s;
  s.reorderList(node.next);
  for (ListNode* p = node.next; p; p = p->next)
    cout << p->val << " ";
  cout << endl;
  ListNode* p = node.next;
  while (p) {
    ListNode* tmp = p->next;
    delete p;
    p = tmp;
  }
  return 0;
} 
