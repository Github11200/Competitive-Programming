#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/text-justification/description/
  Runtime: 100.0%
  Memory: 5.86%
******************************************/

vector<string> fullJustify(vector<string> &words, int maxWidth) {
  vector<vector<string>> lines;
  vector<string> line;

  int currentLength = 0;
  for (int i = 0; i < words.size(); ++i) {
    int previousSpace = i == 0 ? 0 : 1;
    int newLength = words[i].size() + previousSpace;

    if (currentLength + newLength <= maxWidth) {
      line.push_back(words[i]);
      currentLength += newLength;
    } else {
      lines.push_back(line);
      line = vector<string>({words[i]});
      currentLength = words[i].size();
    }
  }

  lines.push_back(line);

  vector<string> res;
  for (int i = 0; i < lines.size() - 1; ++i) {
    int wordsLength = 0;
    for (auto word : lines[i])
      wordsLength += word.size();

    int spaces = maxWidth - wordsLength;
    int n = lines[i].size() - 1;
    string currentLine;

    for (auto word : lines[i]) {
      currentLine += word;
      if (n == 0)
        continue;
      currentLine += string(ceil(static_cast<double>(spaces) / n), ' ');
      spaces -= ceil(static_cast<double>(spaces) / n);
      --n;
    }

    if (n == 0 && lines[i].size() == 1)
      currentLine += string(spaces, ' ');

    res.push_back(currentLine);
  }

  string lastLine;
  for (int i = 0; i < lines.back().size(); ++i) {
    lastLine += lines.back()[i];
    if (i < lines.back().size() - 1)
      lastLine += ' ';
  }
  lastLine += string(maxWidth - lastLine.size(), ' ');
  res.push_back(lastLine);

  return res;
}

int main() { return 0; }