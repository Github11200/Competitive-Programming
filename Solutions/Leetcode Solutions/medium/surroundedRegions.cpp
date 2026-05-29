#include "../../../helperFunctions.h"
#include <bits/stdc++.h>
#include <vector>

/******************************************
  Link: https://leetcode.com/problems/surrounded-regions/description/
  Runtime: 23.41%
  Memory: 10.49%
******************************************/

using namespace std;

set<pair<int, int>> invalidPositions;

bool isValid(vector<vector<char>> &board, pair<int, int> position) {
  if (position.first < 0 || position.first == board.size() || position.second < 0 || position.second == board[0].size())
    return false;
  return true;
}

void findInvalid(vector<vector<char>> &board, pair<int, int> current, set<pair<int, int>> &previous) {
  invalidPositions.insert(current);
  vector<pair<int, int>> nextPositions({pair<int, int>(current.first + 1, current.second), pair<int, int>(current.first - 1, current.second), pair<int, int>(current.first, current.second + 1), pair<int, int>(current.first, current.second - 1)});

  for (auto nextPosition : nextPositions) {
    if (!isValid(board, nextPosition) || previous.count(nextPosition) || board[nextPosition.first][nextPosition.second] == 'X')
      continue;
    previous.insert(nextPosition);
    findInvalid(board, nextPosition, previous);
  }
}

void solve(vector<vector<char>> &board) {
  if (board.size() < 3 || board[0].size() < 3)
    return;

  for (int i = 0; i < board[0].size(); ++i) {
    if (invalidPositions.count(pair<int, int>(0, i)) == 0 && board[0][i] == 'O') {
      set<pair<int, int>> previous;
      findInvalid(board, pair<int, int>(0, i), previous);
    }

    if (invalidPositions.count(pair<int, int>(board.size() - 1, i)) == 0 && board[board.size() - 1][i] == 'O') {
      set<pair<int, int>> previous;
      findInvalid(board, pair<int, int>(board.size() - 1, i), previous);
    }
  }

  for (int i = 1; i < board.size() - 1; ++i) {
    if (invalidPositions.count(pair<int, int>(i, 0)) == 0 && board[i][0] == 'O') {
      set<pair<int, int>> previous;
      findInvalid(board, pair<int, int>(i, 0), previous);
    }

    if (invalidPositions.count(pair<int, int>(i, board[0].size() - 1)) == 0 && board[i][board[0].size() - 1] == 'O') {
      set<pair<int, int>> previous;
      findInvalid(board, pair<int, int>(i, board[0].size() - 1), previous);
    }
  }

  for (int i = 1; i < board.size() - 1; ++i)
    for (int j = 1; j < board[0].size() - 1; ++j)
      if (invalidPositions.count(pair<int, int>(i, j)) == 0)
        board[i][j] = 'X';
}

int main() {
  vector<vector<char>> test = {{'O', 'X', 'X', 'O', 'X'}, {'X', 'O', 'O', 'X', 'O'}, {'X', 'O', 'X', 'O', 'X'}, {'O', 'X', 'O', 'O', 'O'}, {'X', 'X', 'O', 'X', 'O'}};
  solve(test);
  display2DVector(test);

  return 0;
}
