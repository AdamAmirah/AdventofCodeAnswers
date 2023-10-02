#include <bits/stdc++.h>

#include <cctype>
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <string>
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

stack<char> reverseStack(stack<char> &st) {
  stack<char> newSt;
  while (!st.empty()) {
    newSt.push(st.top());
    st.pop();
  }
  return newSt;
}

void shift(map<int, stack<char>> &lists, int amount, int from, int to) {
  while (amount > 0) {
    --amount;
    if (!lists[from].empty()) {
      lists[to].push(lists[from].top());
      lists[from].pop();
    }
  }
}

void readStack(string line, map<int, stack<char>> &lists) {
  int linecnt = 1;
  int empty = 0;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] == ' ') empty++;
    if (empty == 4) {
      linecnt++;
      empty = 0;
    }
    if (line[i] == '[') {
      empty = 0;
      lists[linecnt].push(line[i + 1]);
      linecnt++;
    }
  }
}
int main() {
  string line;
  map<int, stack<char>> stackLists;
  int flag = 0;
  while (getline(cin, line)) {
    if (line[1] == '1' || line.empty()) continue;
    if (line[0] == 'm') {
      if (!flag) {
        flag++;
        for (int i = 1; i <= stackLists.size(); i++)
          stackLists[i] = reverseStack(stackLists[i]);
      }

      vector<int> ve;
      std::istringstream iss(line);
      string number;
      while (iss >> number) {
        if (isdigit(number[0])) {
          int val = stoi(number);
          ve.pb(val);
        }
      }

      shift(stackLists, ve[0], ve[1], ve[2]);

    } else {
      readStack(line, stackLists);
    }
  }

  // final answer
  for (int i = 1; i <= stackLists.size(); i++) {
    cout << stackLists[i].top();
  }
  return 0;
}
