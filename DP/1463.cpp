#include <bits/stdc++.h>
using namespace std;

const int MAX = 1'000'005;
int n;
int d[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  d[1] = 0;
  for (int i = 2; i <= n; i++) {
    d[i] = d[i - 1] + 1;
    if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
    if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
  }

  cout << d[n] << "\n";
}