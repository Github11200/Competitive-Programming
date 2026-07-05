#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/gray-code/description/
  Runtime: 100.00%
  Memory: 14.96%
******************************************/

vector<int> grayCode(int n) {
  if (n == 1)
    return vector<int>({0, 1});

  vector<int> res = grayCode(n - 1);

  for (int i = res.size() - 1; i >= 0; --i)
    res.push_back((1 << (n - 1)) | res[i]);

  return res;
}

int main() {
  vector<int> res = grayCode(3);
  return 0;
}
