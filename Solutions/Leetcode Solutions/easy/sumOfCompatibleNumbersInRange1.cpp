#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/description/
  Runtime: 100.00%
  Memory: 42.75%
******************************************/

int sumOfGoodIntegers(int n, int k) {
  int max = n + k, min = 1;

  if (n > k)
    min = n - k;

  int s = 0;
  for (int i = min; i <= max; ++i)
    if ((n & i) == 0)
      s += i;

  return s;
}

int main() { return 0; }
