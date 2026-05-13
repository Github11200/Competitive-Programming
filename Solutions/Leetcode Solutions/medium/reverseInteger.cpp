#include <bits/stdc++.h>
#include <cmath>
#include <locale>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/reverse-integer/description/
  Runtime: 100.00%
  Memory: 19.44%
******************************************/

int reverse(int x) {
  if (x == 0)
    return 0;

  int numberOfDigits = floor(log10(abs(static_cast<long>(x))));

  int reversed = 0;
  for (int i = numberOfDigits; i >= 0; --i) {
    long long valueToAdd =
        pow(10, numberOfDigits - i) * static_cast<int>(x / pow(10, i));
    if (reversed + valueToAdd > pow(2, 31) - 1 ||
        reversed + valueToAdd < -pow(2, 31))
      return 0;

    reversed += valueToAdd;
    x %= static_cast<int>(pow(10, i));
  }

  return reversed;
}

int main() {
  reverse(123);
  return 0;
}
