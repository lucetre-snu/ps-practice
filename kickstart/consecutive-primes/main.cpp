#include <bits/stdc++.h>
using namespace std;
long z;

bool isPrime(long p) {
  if (p <= 2) return p==2;
  if (p % 2 == 0) return false;
  for (long i = 3; i*i <= p; i += 2)
    if (p % i == 0) return false;
  return true;
}

long ltPrime(long p) {
  if (--p % 2 == 0) p--;
  while (! isPrime(p) && p > 2) p -= 2;
  return p>2 ? p : 2;
}

long gtPrime(long p) {
  if (++p % 2 == 0) p++;
  while (! isPrime(p)) p += 2;
  return p;
}

long process() {
  long s = long(sqrt(z));
  long pg = gtPrime(s);
  long pl = ltPrime(pg);
  if (pg*pl - z <= 0) return pg*pl;

  long p = ltPrime(pl);
  pg = pl;
  pl = p;
  if (pg*pl - z <= 0) return pg*pl;
  
  p = ltPrime(pl);
  pg = pl;
  pl = p;
  if (pg*pl - z <= 0) return pg*pl;
}

int main() {
  freopen("input.txt", "r", stdin);
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> z;
    cout << "Case #" << t << ": ";
    cout << process() << endl;
  }
}