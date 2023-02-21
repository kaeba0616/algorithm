#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
const int MAX = 1005;
char board[MAX][MAX];
int dist[MAX][MAX][2];

pair<int, int> d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<tuple<int, int, int>> Q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> board[i][j];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      for (int k = 0; k < 2; k++) dist[i][j][k] = -1;

  Q.push({0, 0, 0});
  dist[0][0][0] = 1;
  while (!Q.empty()) {
    int x, y, b;
    tie(x, y, b) = Q.front();
    int cur = dist[x][y][b];
    if (x == N - 1 && y == M - 1) {
      cout << cur << "\n";
      break;
    }
    Q.pop();
    for (auto nxt : d) {
      int nx = x + nxt.X;
      int ny = y + nxt.Y;
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (board[x][y] == '1' && !b && dist[nx][ny][1] == -1) {
        dist[nx][ny][1] = cur + 1;
        Q.push({nx, ny, 1});
      }
      if (board[x][y] == '0' && dist[nx][ny][b] == -1) {
        dist[nx][ny][b] = cur + 1;
        Q.push({nx, ny, b});
      }
    }
  }
  if (dist[N - 1][M - 1][0] == -1 && dist[N - 1][M - 1][1] == -1)
    cout << "-1"
         << "\n";
}