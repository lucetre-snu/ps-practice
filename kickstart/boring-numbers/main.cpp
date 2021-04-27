#include <bits/stdc++.h>
#define M 20
typedef long long ll;
using namespace std;
ll l, r;
ll b[M+1];

ll boringNumbers(ll n, bool toggle) {
    if (n < 10) {
        return toggle ? (n+1)/2 : n/2+1;
    }
    int digits = 1;
    ll m = n;
    ll cnt = 0, mul = 1;
    while (m / 10) {
        digits++;
        mul *= 10;
        m /= 10;
    }
    for (int i = 0; i < digits; i++) cnt += b[i];
    cnt += m/2 * b[digits-1];
    if (toggle == false) {
        cout << "hello " << n << endl;
        return 0;
    }
    cout << cnt;
    cnt += (m%2 == toggle) && boringNumbers(n-m*mul, !toggle);
    

    return cnt;
}

ll process() {
    cout << endl;
    return boringNumbers(r, false) - boringNumbers(l-1, false);
}

bool isBoring(int n) {
    vector<int> v;
    while (n/10) {
        v.push_back(n%10);
        n /= 10;
    }
    v.push_back(n);
    for (int i = 0; i < v.size(); i++) {
        int j = v.size() - i;
        if ((j % 2) != (v[i] % 2)) return false;
    }
    return true;
}

void temp() {
    int cnt = 0;
    for (int i = 1; i < 30; i++) {
        cnt += isBoring(i);
        if (cnt != boringNumbers(i, false))
            cout << i << ": " << cnt << "," << boringNumbers(i, false) << endl;
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    b[1] = 5;
    for (int i = 2; i < M; i++) b[i] = 5*b[i-1];
    temp();
    
    cout << boringNumbers(12, true) << endl;

    // for (int t = 1; t <= T; t++) {
    //     cin >> l >> r;
    //     cout << "Case #" << t << ": ";
    //     cout << process() << endl;
    // }
    return 0;
}