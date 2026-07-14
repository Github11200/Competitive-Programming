#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<string> res;
vector<string> current;

void dfs(string s, int n) {
  if (n == 1) {
    if (s.size() > 3 || s.size() == 0 || stoi(s) > 255 || (s[0] == '0' && s.size() > 1))
      return;
    string curr;
    for (int i = 0; i < current.size(); ++i)
      curr += current[i] + ".";
    curr += s;
    res.push_back(curr);
  }

  string currentString = "";
  for (int i = 0; i < s.size(); ++i) {
    currentString.push_back(s[i]);

    if (stoi(currentString) > 255)
      break;

    current.push_back(currentString);
    dfs(s.substr(i + 1, s.size() - i - 1), n - 1);
    current.pop_back();

    if (currentString == "0")
      break;
  }
}

vector<string> restoreIpAddresses(string s) {
  if (s.size() < 4 || s.size() > 12)
    return vector<string>({});
  dfs(s, 4);

  return res;
}

int main() {
  restoreIpAddresses("25525511135");
  return 0;
}
