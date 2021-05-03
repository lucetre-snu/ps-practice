#include <bits/stdc++.h>
using namespace std;
#define M 1000
int a[M+1];

int main() {
    int res = 0;
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++) res += (n-i)*a[i];
    cout << res;
    return 0;
}