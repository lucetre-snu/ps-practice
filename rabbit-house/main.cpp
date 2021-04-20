#include <bits/stdc++.h>
#define M 300
using namespace std;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int a[M+1][M+1], b[M+1][M+1];
int r, c;
priority_queue<pair<int, pair<int,int>>> Q;

void input() {
  Q = priority_queue<pair<int, pair<int,int>>>();
  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++) {
      b[y][x] = 0;
      bool flag = false;
      for (int i = 0; i < 4; i++) {
        int ty = y + dy[i];
        int tx = x + dx[i];
        if (ty >= 0 && tx >= 0 && ty < r && tx < c)
          flag |= a[y][x] + 1 < a[ty][tx];
      }
      if (!flag)
        Q.push(make_pair(a[y][x], make_pair(y, x)));
    }
}

long process() {
  // for (int y = 0; y < r; y++) {
  //   for (int x = 0; x < c; x++)
  //     cout << a[y][x] << " ";
  //   cout << endl;
  // }
  // cout << endl;

  while (! Q.empty()) {
    pair<int, pair<int, int>> f = Q.top(); Q.pop();
    int fh = f.first;
    int fy = f.second.first;
    int fx = f.second.second;

    for (int i = 0; i < 4; i++) {
      int ty = fy + dy[i];
      int tx = fx + dx[i];
      if (ty >= 0 && tx >= 0 && ty < r && tx < c) {
        if (a[ty][tx] < a[fy][fx]-1) {
          int newh = a[fy][fx]-1;
          b[ty][tx] = newh - a[ty][tx];
          a[ty][tx] = newh;
          Q.push(make_pair(a[ty][tx], make_pair(ty, tx)));
        }
      }
    }
  }
  
  long res = 0;
  for (int y = 0; y < r; y++)
    for (int x = 0; x < c; x++)
      res += b[y][x];

  // for (int y = 0; y < r; y++) {
  //   for (int x = 0; x < c; x++)
  //     cout << a[y][x] << " ";
  //   cout << endl;
  // }

  return res;
}

int main() {
  freopen("input.txt", "r", stdin);
  int T, res;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        cin >> a[i][j];
    input();
    long res = process();
    cout << "Case #" << t << ": " << res << endl;
  }

  return 0;
}