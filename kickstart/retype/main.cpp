#include <bits/stdc++.h>
using namespace std;
int n, k, s;

int process() {
    return min(k + n, (k-s) + (n-s) + k);
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> k >> s;
        cout << "Case #" << t << ": ";
        cout << process() << endl;
    }
    return 0;
}