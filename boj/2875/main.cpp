#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n > 2 * m) {
        k -= n - 2 * m;
        n = 2 * m;
    }
    else {
        k -= n % 2;
        n = n / 2 * 2;
        k -= m - n / 2;
        m = n / 2;
    }
    if (k <= 0) {
        cout << m;
    }
    else {
        cout << m - ((k - 1) / 3 + 1);
    }

    return 0;
}