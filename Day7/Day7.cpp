#include <bits/stdc++.h>
#include <pthread.h>

#include <any>
#include <cctype>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#define sl(n) scanf("%lld", &n)
#define fo(n) for (int i = 1; i <= n; ++i)
#define f(n) for (int i = 0; i < n; ++i)
#define ll long long
#define pb push_back
#define pf printf
#define F first
#define S second
using namespace std;

ll finalAns = 0;
ll partTwoAns = INT_MAX;
class Directory {
 public:
  string name;
  Directory* parent;
  unordered_map<string, Directory> subDirs;
  unordered_map<string, ll> files;
  ll totalSize = 0;

  Directory() {}
  Directory(string name, Directory* parent = nullptr) {
    this->name = name;
    this->parent = parent;
  }

  void addSubDir(string name) {
    int count = 1;

    while (subDirs.find(name) != subDirs.end()) {
      name = name + to_string(count);
      count++;
    }

    subDirs[name] = Directory(name, this);
  }

  void addFile(string name, ll size) {
    files[name] = size;
    this->totalSize += size;
  }
};

Directory* changeDirectory(Directory* currentDir, string name) {
  if (name == "parent") {
    if (currentDir->parent) {
      return currentDir->parent;
    } else
      return currentDir;
  } else {
    if (currentDir->subDirs.find(name) != currentDir->subDirs.end()) {
      return &currentDir
                  ->subDirs[name];  // return the found dir as the current one
    } else {
      // cout << "this is not right dawg ....";
      return currentDir;
    }
  }
}
void traversePartOne(Directory* directory) {
  // part one
  if (directory->totalSize <= 100000) {
    finalAns += directory->totalSize;
  }
  for (auto& subDir : directory->subDirs) {
    traversePartOne(&subDir.second);
  }

  return;
}
void traversePartTwo(Directory* directory, ll remaining) {
  // part two
  if (directory->totalSize >= remaining && directory->totalSize < partTwoAns) {
    partTwoAns = directory->totalSize;
  }
  for (auto& subDir : directory->subDirs) {
    traversePartTwo(&subDir.second, remaining);
  }

  return;
}

void calculateTotalSizes(Directory* directory) {
  for (auto& subDir : directory->subDirs) {
    calculateTotalSizes(&subDir.second);
    directory->totalSize += subDir.second.totalSize;
  }
}

int main() {
  string line;
  Directory root("/");
  Directory* currentDir = &root;

  while (getline(cin, line)) {
    if (line[2] == 'c') {
      if (line[5] == '.') {
        // go back to parent
        currentDir = changeDirectory(currentDir, "parent");
      } else {
        // chnage dir
        string newDirName = line.substr(5, line.size() - 1);
        currentDir = changeDirectory(currentDir, newDirName);
      }
    }

    if (line[0] != '$') {    // after ls
      if (line[0] == 'd') {  // if it is a dir
        string dirName = line.substr(4, line.size() - 1);
        currentDir->addSubDir(dirName);
      } else {  // it is a file
        int end = line.find(' ');
        string size = line.substr(0, end);
        ll sizeval = stoll(size);
        string fileName = line.substr(end, line[line.size() - 1]);
        currentDir->addFile(fileName, sizeval);
      }
    }
  }

  calculateTotalSizes(&root);

  // part one answer
  traversePartOne(&root);
  cout << finalAns << endl;

  // part two answer

  traversePartTwo(&root, 30000000 - (70000000 - root.totalSize));
  cout << partTwoAns << endl;
  return 0;
}
