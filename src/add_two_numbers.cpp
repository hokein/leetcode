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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *p1, *p2;
    ListNode dummy_node(0);
    ListNode *cur = &dummy_node;
    p1 = l1; p2 = l2;
    int add = 0;
    while (p1 || p2) {
      if (!p1 || !p2) {
        if (!p1) {
          cur->next = new ListNode((p2->val+add)%10);
          add = (p2->val+add)/10;
          p2 = p2->next;
        } else {
          cur->next = new ListNode((p1->val+add)%10);
          add = (p1->val+add)/10;
          p1 = p1->next;
        }
        cur = cur->next;
        continue;
      }
      cur->next = new ListNode(p1->val+p2->val+add);
      cur = cur->next;
      add = cur->val/10;
      cur->val %= 10;
      p1 = p1->next;
      p2 = p2->next;
    }
    if (add != 0)
      cur->next = new ListNode(add);
    return dummy_node.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  ListNode *p1 = new ListNode(9);
  p1->next = new ListNode(9);

  ListNode *p2 = new ListNode(1);
  Solution s;
  ListNode *ret  = s.addTwoNumbers(p1, p2);
  ListNode *cur = ret;
  while (cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  return 0;
} 
