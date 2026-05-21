#include <bits/stdc++.h>

using namespace std;

int main() {
  string num;
  cin >> num;

  string output;
  for (auto c : num) {
    int digit = c - '0';
    if (9 - digit < digit)
      output += c;
  }

  cout << output << endl;

  return 0;
}
