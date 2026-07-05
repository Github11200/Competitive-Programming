#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/bulls-and-cows/description/
  Runtime: 100.00%
  Memory: 31.55%
******************************************/

string getHint(string secret, string guess) {
  int bulls = 0, cows = 0;

  unordered_map<int, int> c;
  for (int i = 0; i < guess.size(); ++i) {
    if (secret[i] == guess[i])
      ++bulls;
    else
      ++c[guess[i] - '0'];
  }

  for (int i = 0; i < secret.size(); ++i) {
    int currentNum = secret[i] - '0';

    if (secret[i] != guess[i] && c.count(currentNum) > 0 && c[currentNum] > 0) {
      ++cows;
      --c[currentNum];
    }
  }

  return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main() { return 0; }
