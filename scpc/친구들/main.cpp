#include <bits/stdc++.h>
#define M 100000
using namespace std;
int a[M+1], c[M+1];
int n;

bool process(int k) {
    queue<int> Q;
    Q.push(k);
    while (! Q.empty()) {
        int f = Q.front(); Q.pop();
        if (c[f]) return false;
        else c[f] = 1;
        if (f+a[f] < n) 
            Q.push(f+a[f]);
    }
    return true;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int res = 0;
        memset(c, 0, n*sizeof(int));
        for (int i = 0; i < n; i++) {
            if (c[i] == 0) {
                res += process(i);
            }
        }
        cout << res << endl;
    }
}