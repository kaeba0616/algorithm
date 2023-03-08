#include <bits/stdc++.h>
using namespace std;

int N, K;
int DP[105][100005];
int W[105];
int V[105];

int main() {
  cin >> N >> K;

  for (int i = 1; i <= N; i++) cin >> W[i] >> V[i];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      if (j - W[i] >= 0)
        DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
      else
        DP[i][j] = DP[i - 1][j];
    }
  }
  cout << DP[N][K];
}