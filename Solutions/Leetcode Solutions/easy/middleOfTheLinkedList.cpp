#include "../../../helperFunctions.h"
#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/middle-of-the-linked-list/description/
  Runtime: 100.00%
  Memory: 64.68%
******************************************/

ListNode *middleNode(ListNode *head) {
  ListNode *fast = head, *slow = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

int main() { return 0; }