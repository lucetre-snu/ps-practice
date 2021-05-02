#include <bits/stdc++.h>
#define M 100000
using namespace std;
int a[M+1];
int n, S;

int process() {
    int cnt = 0, res = M+1, s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        cnt++;
        if (s >= S) {
            for (int j = i-cnt+1; j <= i; j++) {
                if (s - a[j] >= S) {
                    s -= a[j];
                    cnt--;
                }
                else break;
            }
            // cout << s << ":" << i-cnt+1 << "~" << i << endl;
            res = min(res, cnt);
        }
    }
    return res < M+1 ? res : 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> S;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << process();
    return 0;
}