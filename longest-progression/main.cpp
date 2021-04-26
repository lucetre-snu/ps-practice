#include <bits/stdc++.h>
#define M 300000
using namespace std;
int n, a[M+1], b[M+1];
int l[M+1], r[M+1];

int process() {

  // cout << endl;
  // for (int i = 1; i < n; i++) {
  //   printf("%3d", b[i]);
  // }
  // cout << endl;
  // for (int i = 1; i < n; i++) {
  //   printf("%3d", l[i]);
  // }
  // cout << endl;
  // for (int i = 1; i < n; i++) {
  //   printf("%3d", r[i]);
  // }
  // cout << endl;
  if (n <= 3) return n;
  int ans = 0;

  for (int i = 0; i < n; i++)
		ans = max({ans, (i<n-2) ? r[i+2]+1 : 0, (i>1) ? l[i-1]+1 : 0});

  for (int i = 0; i < n; i++) {
    int val = 2;
    if (i != 0 && i != n-1 && (a[i+1]-a[i-1])%2 == 0) {
      if (i > 1   && b[i-1] == (a[i+1]-a[i-1])/2) val += l[i-1];
      if (i < n-2 && b[i+2] == (a[i+1]-a[i-1])/2) val += r[i+2];
    }
    ans = max(ans, val);
  }
  return ans + 1;
}

int main() {
  freopen("input.txt", "r", stdin);
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      b[i] = a[i]-a[i-1];
      l[i] = i-1 && (b[i]==b[i-1]) ? l[i-1]+1 : 1;
    }
    for (int i = n-1; i > 0; i--) {
      r[i] = n-i-1 && (b[i+1]==b[i]) ? r[i+1]+1 : 1;
    }
    cout << "Case #" << t << ": ";
    cout << process() << endl;
  }
  return 0;
}