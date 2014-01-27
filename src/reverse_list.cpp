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

class Solution {
 public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head)  
      return head;
    ListNode virtual_node(0);
    virtual_node.next = head;
    ListNode* m_pre = &virtual_node;
    for (int i = 1; i < m; ++i) 
      m_pre = m_pre->next;
    ListNode* m_cur = m_pre->next;
    ListNode* n_cur = &virtual_node;
    for (int i = 0; i < n; ++i)
      n_cur = n_cur->next;
    ListNode* p_pre = m_cur;
    ListNode* p_cur = p_pre->next;
    ListNode* n_next_pos = n_cur->next;
    while (p_cur != n_next_pos) {
      ListNode* p_next = p_cur->next;
      p_cur->next = p_pre;
      p_pre = p_cur;
      p_cur = p_next;
    }
    m_pre->next = n_cur;
    m_cur->next = p_cur;
    return virtual_node.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {1, 2, 3, 4, 5};
  int len = 5;
  ListNode node(1);
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  Solution s;
  node.next = s.reverseBetween(node.next, 2, 4);
  for (ListNode* p = node.next; p; p = p->next)
    cout << p->val << " ";
  cout << endl;
  return 0;
} 
