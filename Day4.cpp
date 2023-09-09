#include <bits/stdc++.h>

#include <iostream>
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

// Part one answer
void partOne(int pair1s, int pair1e, int pair2s, int pair2e, int& total) {
  if (pair1s <= pair2s && pair1e >= pair2e ||
      pair2s <= pair1s && pair2e >= pair1e) {
    total++;
  }
}

// Part two answer
void partTwo(int pair1s, int pair1e, int pair2s, int pair2e, int& total) {
  if (pair1s <= pair2e && pair2s <= pair1e) {
    total++;
  }
}
int main() {
  string line;
  int total1 = 0;
  int total2 = 0;

  while (getline(cin, line)) {
    string part1 = line.substr(0, line.find(","));
    string part2 = line.substr(line.find(",") + 1);
    int pair1s = stoi(part1.substr(0, part1.find("-")));
    int pair1e = stoi(part1.substr(part1.find("-") + 1));

    int pair2s = stoi(part2.substr(0, part2.find("-")));
    int pair2e = stoi(part2.substr(part2.find("-") + 1));

    partOne(pair1s, pair1e, pair2s, pair2e, total1);

    partTwo(pair1s, pair1e, pair2s, pair2e, total2);
  }

  cout << total1 << endl;
  cout << total2 << endl;
  return 0;
}
