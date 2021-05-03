#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    int res = 1;
    while (n) res *= n--;
    cout << res;
    return 0;
}