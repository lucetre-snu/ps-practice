#include <bits/stdc++.h>
#define M 500000
using namespace std;
long long a[M+1], s[M+1];
int n;

int length(int l, int r) {
    return s[r] - (l ? s[l-1]: 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i] + (i ? s[i-1] : 0);
    }
    int l = 0, r = n-1;
    long long res = 0;
    while (l < r) {
        if (a[l] < a[r])
            res += a[r] * length(l, --r);
        else
            res += a[l] * length(++l, r);
    }
    cout << res;
    return 0;
}