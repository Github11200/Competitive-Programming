#include "../../../helperFunctions.h"
#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/linked-list-cycle/description/
  Runtime: 92.25%
  Memory: 23.85%
******************************************/

bool hasCycle(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return false;

  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      return true;
  }

  return false;
}

int main() { return 0; }