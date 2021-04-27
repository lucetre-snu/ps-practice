#include <bits/stdc++.h>
using namespace std;
int n;
string s;

void process() {
  int ind = 1;
  cout << ind << " ";
  for (int i = 1; i < s.size(); i++) {
    if (s[i] > s[i-1]) ind++;
    else ind = 1;
    cout << ind << " ";
  }
  cout << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n >> s;
    cout << "Case #" << t << ": ";
    process();
  }
  return 0;
}