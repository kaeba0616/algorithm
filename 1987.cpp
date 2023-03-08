#include <bits/stdc++.h>
using namespace std;

const int MAX = 26;

char board[MAX][MAX];
int dist[MAX][MAX];
int R, C;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C;
  for (int i = 1; i <= R; i++)
    for (int j = 1; j <= C; j++) cin >> board[i][j];
}