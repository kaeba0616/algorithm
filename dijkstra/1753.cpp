#include <bits/stdc++.h>
using namespace std;

const int MAX = 20005;
const int INF = 0x7f7f7f7f;

typedef pair<int, int> pii;
#define X first
#define Y second

int V, E, st;

vector<pair<int, int>> edge[MAX];
int d[MAX];
bool chk[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E >> st;
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a].push_back({c, b});
  }
  priority_queue<pii, vector<pii>, greater<pii>> PQ;
  for (int i = 1; i <= V; i++) {
    d[i] = INF;
  }
  d[st] = 0;
  PQ.push({d[st], st});
  while (!PQ.empty()) {
    auto cur = PQ.top();
    PQ.pop();

    if (chk[cur.Y]) continue;
    chk[cur.Y] = true;

    for (auto next : edge[cur.Y]) {
      if (d[next.Y] <= d[cur.Y] + next.X) continue;
      d[next.Y] = d[cur.Y] + next.X;
      PQ.push({d[next.Y], next.Y});
    }
  }
  for (int i = 1; i <= V; i++) {
    if (d[i] == INF) {
      cout << "INF"
           << "\n";
    } else {
      cout << d[i] << "\n";
    }
  }
}