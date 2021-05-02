#include <bits/stdc++.h>
#define N 500000
using namespace std;
int n, m;
int a[N+1];

void process() {
    for (m = 0; m < n; m++) 
        if (a[m] >= 0) break;

    for (int i = m-2; i >= 0; i-=2)             cout << a[i] << " ";
    for (int i = max((m-1)%2, 0); i < m; i+=2)  cout << a[i] << " ";
    for (int i = m; i < n; i+=2)                cout << a[i] << " ";
    for (int i = n-1-(n-m)%2; i >= m+1; i-=2)   cout << a[i] << " ";
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    process();
    return 0;
}