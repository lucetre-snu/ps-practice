#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 20
ll b[M+1];

ll boring(ll n) {
    vector<int> digits;
    ll mul = 1, res = 0;
    int d = 1;

    for (mul = 1; mul <= n/10; mul*=10, d++);
    digits.resize(d+1);

    for (int i = 1; i <= d; i++, mul/=10) {
        digits[i] = n/mul;
        n %= mul;
    }

    for (int i = 1; i < d; i++) res += b[i];

    bool flag = true;
    for (int i = 1; i <= d; i++) {
        if (i % 2) {
            for (int j = 1; j < digits[i]; j+=2) res += b[d-i];
            if (digits[i] % 2 == 0) {
                flag = false;
                break;
            }
        }
        else {
            for (int j = 0; j < digits[i]; j+=2) res += b[d-i];
            if (digits[i] % 2) {
                flag = false;
                break;
            }
        }
    }
    return res+flag;
}

bool isBoring(int n) {
    vector<int> digits;
    ll mul = 1, res = 0;
    int d = 1;

    for (mul = 1; mul <= n/10; mul*=10, d++);
    digits.resize(d+1);

    for (int i = 1; i <= d; i++, mul/=10) {
        digits[i] = n/mul;
        n %= mul;
    }

    for (int i = 1; i <= d; i++) 
        if (digits[i] % 2 != i % 2)
            return false;
    return true;
}

int temp(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += isBoring(i);
    return cnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    b[0] = 1;
    for (int i = 1; i <= M; i++) b[i] = b[i-1] * 5;

    /*for (int i = 1; i < 100; i++) {
        if (temp(i) != boring(i)) 
            cout << temp(i) << ", " << boring(i) << endl;
    }
    return 0;
*/

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll L, R;
        cin >> L >> R;
        cout << "Case #" << t << ": ";
        cout << boring(R) - boring(L-1) << endl;
    }
    return 0;
}