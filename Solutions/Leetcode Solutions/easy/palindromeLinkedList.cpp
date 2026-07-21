#include "../../../helperFunctions.h"
#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/palindrome-linked-list/description/
  Runtime: 100.00%
  Memory: 97.43%
******************************************/

bool isPalindrome(ListNode *head) {
  if (head->next == nullptr)
    return true;

  ListNode *fast = head, *slow = head;
  int listSize = 0;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    ++listSize;
  }

  listSize = fast == nullptr ? listSize * 2 : listSize * 2 + 1;

  ListNode *current = head, *previous = nullptr;
  for (int i = 0; i < listSize / 2; ++i) {
    ListNode *next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  if (listSize % 2 != 0)
    slow = slow->next;

  while (slow && previous) {
    if (slow->val != previous->val)
      return false;
    slow = slow->next;
    previous = previous->next;
  }

  return true;
}

int main() { return 0; }