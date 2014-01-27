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

// Partition the ListNode
//
// Solution
//  keep two list, one for elements less than x, the other for elements equal and greater than x.
// 
// Scan the whole list, when meet element < x, merge it to less list and remove from origin list.
// Lastly, combine the two lists, make less list at head of the equal and greater list.
class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    if (!head)
      return head;
    ListNode virtual_node(0);
    ListNode less_node(0);
    virtual_node.next = head;  
    ListNode* p1_pre = &virtual_node;
    ListNode* p1_cur = p1_pre->next;
    ListNode* p2 = &less_node;
    while (p1_cur) {
      // push p1 node to less_node list back, if p1->val < x
      // and remove it from virtual_node list
      if (p1_cur->val < x) {
        ListNode* p1_next = p1_cur->next;
        p2->next = p1_cur;
        p2 = p2->next;
        p2->next = NULL; 
        p1_pre->next= p1_next;
        p1_cur = p1_next;
      } else {
        p1_pre = p1_pre->next;
        p1_cur = p1_cur->next; 
      }
    }
    p2->next = virtual_node.next;
    return less_node.next;
  }
};
 
int main() {
  freopen("test.txt", "r", stdin);
  int a[] = {1, 4, 3, 2, 5, 2};
  int len = 6;
  ListNode node(1);
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  Solution s;
  node.next = s.partition(node.next, 1);
  for (ListNode* p = node.next; p; p = p->next)
    cout << p->val << " ";
  cout << endl;
  return 0;
  return 0;
} 
