#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/
  Runtime: 14.89%
  Memory: 26.87%
******************************************/

int numberOfSpecialChars(string word) {
  unordered_map<char, int> lowercasePositions;
  unordered_map<char, int> uppercasePositions;

  for (int i = 0; i < word.size(); ++i) {
    if (islower(word[i], locale()))
      lowercasePositions[word[i]] = i;
    else if (!uppercasePositions.count(word[i]))
      uppercasePositions[word[i]] = i;
  }

  int n = 0;
  for (auto position : uppercasePositions) {
    char c = tolower(position.first);
    int index = position.second;

    if (lowercasePositions.count(c) && lowercasePositions[c] < index)
      ++n;
  }

  return n;
}

int main() { return 0; }
