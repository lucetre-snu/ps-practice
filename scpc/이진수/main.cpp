#include <bits/stdc++.h>
#define M 50000
using namespace std;
int n, m;
int a[M+1], b[M+1];

int before(int k) {
    if (k-m < 0) return 2;
    return a[k-2*m] ? 2 : 1;
}

int after(int k) {
    if (k+m >= n) return 2;
    return a[k+2*m] ? 2 : 1;
}

void process() {
    for (int i = 0; i < n; i++) a[i] = 2;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {        
            if (i+m < n)    a[i+m] = 0;
            if (i-m >= 0)   a[i-m] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        if (i+m < n)    a[i+m] = b[i];
        if (n-m-i > 0)  a[n-m-i-1] = b[n-i-1];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != 2) continue;
        int bef = before(i);
        int aft = after(i);
        if (bef != 2)       a[i] = bef;
        else if (aft != 2)  a[i] = aft;
        else                a[i] = 0;
    }
    for (int i = 0; i < n; i++) 
        cout << a[i];
    cout << endl;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << endl;
        string s;
        cin >> n >> m >> s;
        for (int i = 0; i < n; i++) b[i] = s[i]-'0';
        process();
    }
    return 0;
}