#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/remove-duplicate-letters/description/
  Runtime: 100.00%
  Memory: 5.91%
******************************************/

string removeDuplicateLetters(string s) {
  set<char> added;
  unordered_map<char, int> freq;

  for (int i = 0; i < s.size(); ++i)
    ++freq[s[i]];

  stack<char> q;
  for (int i = 0; i < s.size(); ++i) {
    --freq[s[i]];

    if (added.count(s[i]) > 0)
      continue;
    if (!q.empty() && q.top() > s[i]) {
      while (!q.empty() && q.top() > s[i] && freq[q.top()] != 0) {
        added.erase(q.top());
        q.pop();
      }
    }

    q.push(s[i]);
    added.insert(s[i]);
  }

  string newStr;
  while (!q.empty())
    newStr.push_back(q.top()), q.pop();

  reverse(newStr.begin(), newStr.end());

  return newStr;
}

int main() {
  removeDuplicateLetters("bbcaac");
  return 0;
}
