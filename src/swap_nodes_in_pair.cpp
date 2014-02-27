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
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode* p0 = &dummy;
    ListNode* p1 = p0->next;      
    ListNode* p2 = p1->next;

    while (p2) {
      p0->next = p2;
      p1->next = p2->next;
      p2->next = p1;

      p0 = p1;
      p1 = p1->next;
      if (!p1) break;
      p2 = p1->next;
    }
    return dummy.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  Solution s;
  ListNode* tmp = s.swapPairs(head);
  while (tmp) {
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
} 
