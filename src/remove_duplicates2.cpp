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

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head)
      return head;
    ListNode virtual_node(0);
    virtual_node.next = NULL;
    ListNode* rear = &virtual_node;
    ListNode* cur = head;
    while (cur) {
      ListNode* p = cur->next;
      // detect duplicated elements.
      int cnt = 0;
      while (p) {
        if (p->val != cur->val)
          break;
        ++cnt;
        p = p->next;
      }
      if (cnt == 0) { // no duplicated element, append to rear of new list.
        rear->next = cur;
        cur->next = NULL;
        rear = cur;
      }
      cur = p;
    }
    return virtual_node.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {1, 1, 3, 4, 4};
  int len = 2;
  ListNode node(1);
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  Solution s;
  node.next = s.deleteDuplicates(node.next);
  for (ListNode* p = node.next; p; p = p->next)
    cout << p->val << " ";
  cout << endl;
  return 0;
} 
