#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

//Definition for singly-linked list with a random pointer.
//
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// Deep coy random list.
//
// O(n) with O(1) space.
//
// Solution:
// 1. Create n elements copy node, and insert them between each two origin list nodes.
//          ------                 ----------
//         |    \/                |         \/
//    1 -> 1 -> 1  then 1 -> 2 -> 1 -> 2 -> 1 -> 2
//    |   /\           |         /\
//    ----|            ----------|
//
// 2. Set the random field of copy node.
//    cur : the pointer points to orgin node.
//   cur->next = cur->random->next.
//
// 3. Restore the combined list in step(1)
class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head)      
      return head;
    // insert new node between each origin node.
    // 1 means nodes of origin list, 2 means node of copy list.
    // 
    // 1 1 1 1  => 1 2 1 2 1 2 1 2
    RandomListNode* cur = head;
    while (cur) { 
      RandomListNode* new_node = new RandomListNode(cur->label);
      new_node->next = cur->next;
      cur->next = new_node;
      cur = new_node->next;
    }

    // copy random field.
    // cur points to the node of origin list.
    //
    // cur->next is the copy node of cur
    // cur->next->random = cur->random->next
    cur = head;
    while (cur) {
      if (cur->random)
        cur->next->random = cur->random->next;
      cur = cur->next->next;
    }

    // restore the two lists.
    cur = head;
    RandomListNode virtual_node(0);
    RandomListNode* p = &virtual_node;
    while (cur) {
      p->next = cur->next;
      p = p->next;
      cur->next = p->next;
      p->next = NULL;
      cur = cur->next;
    }
    return virtual_node.next;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int a[] = {1, 2, 3, 4, 4};
  int len = 5;
  vector<RandomListNode* > v(len);
  for (int i = 0; i < len; ++i) {
    v[i] = new RandomListNode(a[i]);
  }
  RandomListNode* list = v[0];
  for (int i = 0; i < len-1; ++i) {
    v[i]->next = v[i+1];
    v[i]->random = v[i+1];
  }
  v[len-1]->next = NULL;
  for (RandomListNode* p = list; p ; p = p->next) {
    cout << p->label << " " << p->random << " ";
  }
  cout << endl;
  Solution s;
  list = s.copyRandomList(list);
  for (RandomListNode* p = list; p ; p = p->next) {
    cout << p->label << " " << p->random << " ";
  }
  cout << endl;
  return 0;
} 
