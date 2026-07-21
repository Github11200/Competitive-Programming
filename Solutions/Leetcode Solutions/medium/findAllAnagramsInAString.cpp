#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
  Runtime: 100.00%
  Memory: 63.49%
******************************************/

vector<int> findAnagrams(string s, string p) {
  if (p.size() > s.size())
    return vector<int>();

  vector<int> pCount(26, 0);
  for (auto c : p)
    pCount[c - 'a']++;

  vector<int> count(26, 0);
  for (int i = 0; i < p.size() - 1; ++i)
    count[s[i] - 'a']++;

  vector<int> res;
  for (int i = p.size() - 1; i < s.size(); ++i) {
    count[s[i] - 'a']++;
    if (pCount == count)
      res.push_back(i - p.size() + 1);
    count[s[i - p.size() + 1] - 'a']--;
  }

  return res;
}

int main() { return 0; }