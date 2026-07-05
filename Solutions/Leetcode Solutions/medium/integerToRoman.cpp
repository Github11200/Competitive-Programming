#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/integer-to-roman/description/
  Runtime: 100.0%
  Memory: 70.47%
******************************************/

string intToRoman(int num) {
  vector<pair<int, char>> values = {
      {1000, 'M'}, {500, 'D'}, {100, 'C'}, {50, 'L'}, {10, 'X'}, {5, 'V'}, {1, 'I'},
  };

  string s = to_string(num);
  int digits = s.size();

  string res;
  for (int i = 0; i < s.size(); ++i, --digits) {
    int currentNum = (s[i] - '0') * pow(10, digits - 1);

    if (s[i] - '0' == 4 || s[i] - '0' == 9) {
      if (currentNum == 4)
        res.append("IV");
      else if (currentNum == 9)
        res.append("IX");
      else if (currentNum == 40)
        res.append("XL");
      else if (currentNum == 90)
        res.append("XC");
      else if (currentNum == 400)
        res.append("CD");
      else if (currentNum == 900)
        res.append("CM");
      continue;
    }

    for (auto value : values) {
      if (currentNum / value.first < 1)
        continue;
      res.append(currentNum / value.first, value.second);
      currentNum -= (currentNum / value.first) * value.first;
      if (currentNum == 0)
        break;
    }
  }

  return res;
}

int main() { return 0; }
