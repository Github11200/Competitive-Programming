#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/longest-palindrome/description/
  Runtime: 100.00%
  Memory: 62.69%
******************************************/

int longestPalindrome(string s) {
  unordered_map<char, int> freqs;
  for (int i = 0; i < s.size(); ++i)
    ++freqs[s[i]];

  int maxLength = 0;
  bool takenOdd = false;

  for (auto &freq : freqs) {
    if (freq.second % 2 != 0)
      takenOdd = true;
    maxLength += freq.second % 2 == 0 ? freq.second : freq.second - 1;
  }

  return takenOdd ? maxLength + 1 : maxLength;
}

int main() { return 0; }
