#include <bits/stdc++.h>

using namespace std;

int firstUniqChar(string s) {
  vector<int> freq(26, 0);
  for (int i = 0; i < s.size(); ++i)
    ++freq[s[i] - 'a'];

  for (int i = 0; i < s.size(); ++i) {
    if (freq[s[i] - 'a'] > 1)
      continue;
    return i;
  }

  return -1;
}

int main() {
  firstUniqChar("loveleetcode");
  return 0;
}