#include <bits/stdc++.h>

using namespace std;

int getIndex(char c) {
  if (isupper(c))
    return c - 'A';
  return c - 'a' + 26;
}

string minWindow(string s, string t) {
  if (t.size() > s.size())
    return "";

  unordered_map<char, int> map;
  for (int i = 0; i < t.size(); ++i)
    map[t[i]]++;

  int count = t.size(), j = 0, minLength = INT_MAX;
  pair<int, int> p;
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];

    if (map[c] > 0)
      count--;
    map[c]--;

    while (count == 0) {
      if (i - j + 1 < minLength) {
        minLength = i - j + 1;
        p = pair<int, int>(j, i);
      }

      char c2 = s[j++];
      if (map[c2] == 0)
        count++;
      map[c2]++;
    }
  }

  return minLength == INT_MAX ? "" : s.substr(p.first, minLength);
}

int main() {
  minWindow("a", "a");
  return 0;
}