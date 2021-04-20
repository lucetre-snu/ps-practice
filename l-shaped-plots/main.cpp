#include <bits/stdc++.h>
#define M 1000
using namespace std;
int a[M+1][M+1];
int s[4][M+1][M+1];
int r, c;

int Lcount(pair<int,int> p) {
  if (p.first < 2 || p.second < 2) return 0;
  return (min(p.first/2, p.second) + min(p.second/2, p.first)-2);
}

int process() {
  int res = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      for (int k = 0; k < 4; k++)
        s[k][i][j] = 0;
        
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j]) {
        s[0][i][j] = j ? s[0][i][j-1]+1 : 1; 
        s[1][i][j] = i ? s[1][i-1][j]+1 : 1; 
      }
      if (a[r-i-1][c-j-1]) {
        s[2][r-i-1][c-j-1] = j ? s[2][r-i-1][c-j]+1 : 1; 
        s[3][r-i-1][c-j-1] = i ? s[3][r-i][c-j-1]+1 : 1; 
      }
    }
  }
  
  for (int k = 0; k < 4; k++)
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        res += Lcount(make_pair(s[k][i][j], s[(k+1)%4][i][j]));
  
  // string dir[4] = {"┘", "└", "┌", "┐",};
  // for (int k = 0; k < 4; k++) {
  //   cout << dir[k] << endl;
  //   for (int i = 0; i < r; i++) {
  //     for (int j = 0; j < c; j++) {
  //       pair<int,int> p(s[k][i][j], s[(k+1)%4][i][j]);
  //       cout << s[k][i][j] << "," << s[(k+1)%4][i][j] << "(" << Lcount(p) <<") ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }
  return res;
}

int main() {
  freopen("input.txt", "r", stdin);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        cin >> a[i][j];
    
    cout << "Case #" << t << ": " << process() << endl;
  }

  return 0;
}