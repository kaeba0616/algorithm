#include <bits/stdc++.h>
using namespace std;

int n, t, d, l, r, arr[100001];
string c;
char x;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> c >> n >> x, l = d = 0, r = n - 1;
    if (n)
      for (int i = 0; i < n; i++) cin >> arr[i] >> x;
    else
      cin >> x;
    for (int i = 0; i < c.length(); i++) {
      if (c[i] == 'R')
        d ^= 1;  // 0 : Original 1 : Flipped
      else {
        if (d)
          r--;
        else
          l++;
        n--;
      }
    }
    if (n < 0)
      cout << "error\n";
    else if (!n)
      cout << "[]\n";
    else {
      cout << "[";
      if (d)
        for (int i = r; i > l; i--) cout << arr[i] << ",";
      else
        for (int i = l; i < r; i++) cout << arr[i] << ",";
      cout << arr[d ? l : r] << "]"
           << "\n";
    }
  }
}
