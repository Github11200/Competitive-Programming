#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/delete-columns-to-make-sorted/description/
  Runtime: 5.02%
  Memory: 6.04%
******************************************/

int minDeletionSize(vector<string> &strs) {
  int numberOfColumnsDeleted = 0;

  set<int> deletedColumns;
  vector<int> previousAsciiValues(strs[0].size());

  for (int i = 0; i < strs[0].size(); ++i)
    previousAsciiValues[i] = static_cast<int>(strs[0][i]);

  for (int i = 1; i < strs.size(); ++i) {
    for (int j = 0; j < strs[i].size(); ++j) {
      if (deletedColumns.count(j) > 0)
        continue;
      if (static_cast<int>(strs[i][j]) < previousAsciiValues[j]) {
        ++numberOfColumnsDeleted;
        deletedColumns.insert(j);
      }

      previousAsciiValues[j] =
          max(previousAsciiValues[j], static_cast<int>(strs[i][j]));
    }
  }

  return numberOfColumnsDeleted;
}

int main() { return 0; }
