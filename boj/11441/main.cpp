#include <bits/stdc++.h>
#define M 100000
using namespace std;
int a[M+1], s[M+1];
int n;
int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        s[i] = a[i] + (i ? s[i-1] : 0);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r-1] - (l-1? s[l-2]: 0));
    }
    return 0;
}