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

class Solution {
 public:
  ListNode *insertionSortList(ListNode *head) {
    if (!head)
      return head;
    ListNode* pre = head;
    ListNode* cur = head->next;
    while (cur) {
      ListNode virtual_node(0);
      virtual_node.next = head;
      ListNode* fp = &virtual_node;
      while (fp->next != cur) {
        if (fp->next->val >= cur->val)
          break;
        fp = fp->next;
      }
      // reach end, already sorted
      if (fp->next == cur) {
        cur = cur->next;
        pre = pre->next;  
        continue;
      }
      ListNode* next_pos = cur->next; // tmp hold next_pos
      pre->next = cur->next;
      cur->next = fp->next;
      fp->next = cur;

      head = virtual_node.next;
      cur = next_pos; 
    }
    return head;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {3, 4, 1};
  int len = 3;
  ListNode node;
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  Solution s;
  node.next = s.insertionSortList(node.next);
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
