#include <bits/stdc++.h>

using namespace std;

unordered_map<char, vector<string>> mapping = {
    {'2', {"a", "b", "c"}}, {'3', {"d", "e", "f"}}, {'4', {"g", "h", "i"}}, {'5', {"j", "k", "l"}}, {'6', {"m", "n", "o"}}, {'7', {"p", "q", "r", "s"}}, {'8', {"t", "u", "v"}}, {'9', {"w", "x", "y", "z"}},
};

vector<string> letterCombinations(string digits) {
  vector<string> res;

  if (digits.size() == 1)
    return mapping[digits[0]];

  vector<string> strs = letterCombinations(digits.substr(1, digits.size() - 1));
  vector<string> currentLetter = mapping[digits[0]];

  for (int i = 0; i < currentLetter.size(); ++i)
    for (int j = 0; j < strs.size(); ++j)
      res.push_back(currentLetter[i] + strs[j]);

  return res;
}

int main() { return 0; }
