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
  ListNode(int x) : val(x), next(NULL) {}
};

// Detect wether a list has a cycle, if so, find the position.
// Solution: O(n), two steps
//
// 1. calculate the cycle's length
// 2. two pointer:
//    * slow pointer => head, fast pointer => head+len, (dis(slow, fast) = len)
//    * eachtime both two pointers move one steps. The first meet position is the position.
//
// How to calculate the cycle's len:
// 
// Using two pointers method(p1 move 1 stpes, p2 move two step)
//  
// Record the steps p1 moves where p1 and p2 first meet. -- s1
// Record the stpes p1 moves where p1 and p2 second meet. -- s2
// Then len = s2 - s1.
// 
// It's easy to understand.
// Since p2 move one stpes faster the p1, so the steps of p1 moves between first time meet and second time
// is equal to the cycle's len.
//
//
// There is another O(n) solution, simpler than the above one.
//
// * When slow and fast pointer meet first time, reset slow pointer to head.
// * slow and fast move forward one steps, the first time meet poisition is the begin poisition.
//
// Explaination, as the above solution.
// Assume slow pointer moved i steps then two pointers meet.
// mu is the distance(head, begin_point)
// len is cycle len
// i = s + k1*(len), k1, k2 is Z 
// 2i = s + k2*(len)
//
// 2i-i = (k2-k1)*len
// i = (k2-k1)*len, i is mutiple of cycle's len.
// So x[i+mu] = x[mu]
//
// The first meet poisition is X[i], begin a pointer from head(X[0])
// eachtime move one steps, the first meet position is x[mu]
// x[mu] = x[i+mu]
class Solution {
 public:
  int cycleLen(ListNode* head) {
    if (!head)      
      return -1;
    ListNode *p1, *p2;
    p1 = head;
    p2 = p1->next;
    int s_first = -1;
    int steps = 0;
    while (p2 && p2->next) {
      if (p2 == p1) {
        if (s_first == -1)
          s_first = steps;
        else 
          return steps-s_first;
      }
      ++steps;
      p1 = p1->next;
      p2 = p2->next->next;
    }
    return -1;
  }
  ListNode *detectCycle(ListNode *head) {
    int len = cycleLen(head);
    if (len == -1)
      return NULL;
    ListNode *p = head;
    ListNode *fp = head;
    for (int i = 0; i < len; ++i) 
      fp = fp->next;
    while (p != fp) {
      p = p->next;
      fp = fp->next;
    }
    return p;
  }
};

int main() {
  int a[] = {2, 3, 4, 1};
  int len = 3;
  ListNode node(1);
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  fr->next = fr;
  Solution s;
  cout << (s.detectCycle(node.next))->val << endl;
  return 0;
} 
