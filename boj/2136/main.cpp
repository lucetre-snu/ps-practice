#include <bits/stdc++.h>
#define M 100000
using namespace std;
int n, l;
int a[M+1], b[M+1];
pair<int, int> p[M+1];

int process1() {
    int maxT = -1, maxD = 0;
    int left = 0;
    for (int i = 0; i < n; i++) {
        int d = (a[i] < 0) ? -1 : +1;
        int t = (a[i] < 0) ? -a[i] : l-a[i];
        if (maxT < t) {
            maxT = t;
            maxD = d;
        }
        left += (d < 0);
    }

    left -= (maxD < 0);
    return p[left].second;
}

int process2() {
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, b[i]);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = make_pair(abs(a[i]), i+1);
        if (a[i] < 0) b[i] = -a[i];
        else b[i] = l - a[i];
    }
    sort(p, p+n);
    cout << process1() << " " << process2() << endl;
    return 0;
}