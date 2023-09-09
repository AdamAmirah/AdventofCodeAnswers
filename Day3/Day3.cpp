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

  while (getline(cin, line)) {
    string str = line;
    map<char, int> visited;
    for (int i = 0; i < str.size() / 2; i++) {
      visited[str[i]]++;
    }

    for (int i = str.size() / 2; i < str.size(); i++) {
      if (visited[str[i]] > 0) {
        total += value[str[i]];
        visited[str[i]] = 0;
      }
    }
  }

  cout << total;
  return 0;
}
