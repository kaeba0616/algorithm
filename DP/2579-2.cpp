#include <bits/stdc++.h>
using namespace std;

const int MAX = 305;

int dp[MAX];
int arr[MAX];
int n, tot;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    tot += arr[i];
  }
  if (n <= 2) {
    cout << tot;
    return 0;
  }
  dp[1] = arr[1];
  dp[2] = arr[2];
  dp[3] = arr[3];
  for (int i = 4; i <= n - 1; i++) dp[i] = min(dp[i - 2], dp[i - 3]) + arr[i];
  cout << tot - min(dp[n - 1], dp[n - 2]) << "\n";
}