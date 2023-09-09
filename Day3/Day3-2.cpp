#include <bits/stdc++.h>
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
  map<char, int> value;
  int total = 0;
  int j = 1;
  for (char c = 'a'; c <= 'z'; ++c) {
    value[c] = j;
    j++;
  }

  for (char c = 'A'; c <= 'Z'; ++c) {
    value[c] = j;
    j++;
  }

  j = 0;
  map<char, int> visited;
  while (getline(cin, line)) {
    j++;
    string str = line;
    for (int i = 0; i < str.size(); i++) {
      if (j == 1 & visited[str[i]] == 0) visited[str[i]]++;
      if (j == 2 & visited[str[i]] == 1) visited[str[i]]++;
      if (j == 3 & visited[str[i]] == 2) visited[str[i]]++;

      if (j == 3 && visited[str[i]] >= 3) {
        total += value[str[i]];
        visited[str[i]] = 0;
      }
    }
    if (j == 3) {
      j = 0;
      visited.clear();
    }
  }

  cout << total;
  return 0;
}
