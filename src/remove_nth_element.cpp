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

// Remove last nth element in one pass.
//
// Using two pointers, slow and fast, dis(fast-slow) = n
// move one steps each times until fast->next = NULL(fast points to the last element)
// head->next is the nth element.
class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode virtual_node(0);
    virtual_node.next = head;
    ListNode *fast = &virtual_node;
    while (n--) {
      if (!fast)
        return head;
      fast = fast->next;
    }
    ListNode *slow = &virtual_node;
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
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
  node.next = s.removeNthFromEnd(node.next, 4);
  for (ListNode* p = node.next; p; p = p->next)
    cout << p->val << " ";
  cout << endl;
  return 0;
} 
