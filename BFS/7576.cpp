#include <bits/stdc++.h>
using namespace std;

int M, N;
const int MAX = 1005;
int arr[MAX][MAX];
bool chk[MAX][MAX];

typedef pair<int, int> pii;
#define X first
#define Y second

queue<pii> Q;

pii d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> arr[i][j];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (arr[i][j] != 1) continue;
      Q.push({i, j});
    }
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    chk[cur.X][cur.Y] = true;
    for (auto nxt : d) {
      int nx = cur.X + nxt.X;
      int ny = cur.Y + nxt.Y;
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (chk[nx][ny]) continue;
      if (arr[nx][ny] != 0) continue;
      arr[nx][ny] = arr[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == 0) {
        cout << -1 << "\n";
        return 0;
      }
      ans = max(ans, arr[i][j]);
    }
  cout << ans - 1 << "\n";
}