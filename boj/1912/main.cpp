#include <bits/stdc++.h>
#define M 100000
#define INF 9e8
using namespace std;
int a[M+1];

int main() {
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    int s = 0, res = -INF;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (s > 0) s += a[i];
        else s = a[i];
        res = max(res, s);
    }
    cout << res;
    return 0;
}