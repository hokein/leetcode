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

// Merge K lists.
//
// O(kn) with O(1) space.
//
// We can use heap to optimize to O(log(k)*n) with O(k) space.
// a heap to maintain the smallest element in k lists head elements.
class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode virtual_node(0);
    ListNode* p = &virtual_node;
    while (true) {
      int min_pos = -1;
      for (int i = 0; i < lists.size(); ++i)
        if (lists[i] && (min_pos == -1 || lists[i]->val < lists[min_pos]->val)) {
          min_pos = i;
        }
      if (min_pos < 0)
        break;
      p->next = lists[min_pos];
      lists[min_pos] = lists[min_pos]->next;
      p = p->next;
      p->next = NULL;
    }
    return virtual_node.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {1, 1, 3, 4, 4};
  int b[] = {5, 6, 8};
  int len = 2;
  ListNode node(1), node2(2);
  ListNode* fr = &node;
  ListNode* fr2 = &node2;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr2->next = new ListNode(b[i]);
    fr = fr->next;
    fr2 = fr2->next;
  }
  Solution s;
  vector<ListNode*> v;
  v.push_back(node.next);
  v.push_back(node2.next);
  node.next = s.mergeKLists(v);
  for (ListNode* p = node.next; p; p = p->next)
    cout << p->val << " ";
  cout << endl;
  return 0;
} 
