#include "../../../helperFunctions.h"
#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/reverse-linked-list/description/
  Runtime: 100.00%
  Memory: 93.42%
******************************************/

ListNode *reverseList(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;

  ListNode *previous = nullptr;
  ListNode *current = head;
  while (current) {
    ListNode *nextNode = current->next;
    current->next = previous;
    previous = current;
    current = nextNode;
  }

  return previous;
}

int main() { return 0; }