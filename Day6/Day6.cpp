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

int main() {
  string line;
  getline(cin, line);

  // sliding window i guess
  int left = 0;
  string ans = "";
  int part1 = 4;
  int part2 = 14;
  map<char, int> firstTime;
  for (int right = left; right < line.size(); right++) {
    if (ans.size() == part1) {
      cout << left + part1;
      return 0;
    }

    if (firstTime[line[right]] > 0) {
      ans = "";
      left++;
      firstTime.clear();
      right = left;
    }
    firstTime[line[right]]++;
    ans += line[right];
  }

  return 0;
}
