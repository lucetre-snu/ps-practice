
#include <bits/stdc++.h>
using namespace std;

int k_goodness(string s, int n) {
  int score = 0;
  for (int i = 0; i < n/2; i++)
    score += (s[i] != s[n-i-1]);
  return score;
}

int main() {
  freopen("input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << "Case #" << i+1 << ": " << abs(k - k_goodness(s, n)) << endl;
  }

  return 0;
}