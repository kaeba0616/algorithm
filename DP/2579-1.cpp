#include <bits/stdc++.h>
using namespace std;

const int MAX = 305;
int dp[MAX][3];
int s[MAX];

int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  dp[1][1] = s[1];
  dp[1][2] = 0;
  dp[2][1] = s[2];
  dp[2][2] = s[1] + s[2];

  for (int i = 3; i <= n; i++) {
    dp[i][1] = max(dp[i - 2][2], dp[i - 2][1]) + s[i];
    dp[i][2] = dp[i - 1][1] + s[i];
  }

  cout << max(dp[n][1], dp[n][2]) << "\n";
}