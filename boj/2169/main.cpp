#include <bits/stdc++.h>
#define M 1000
#define INF 900000000
using namespace std;
int d[2][M+1][M+1], a[M+1][M+1];
int n, m;

int process() {
    d[0][0][0] = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            d[0][i][j] = max(max(d[0][i][j], 
                             (j ? a[i][j]+d[0][i][j-1] : -INF)),
                         max((i ? a[i][j]+d[0][i-1][j] : -INF),
                             (i ? a[i][j]+d[1][i-1][j] : -INF)));
        for (int j = m-1; j >= 0; j--)
            d[1][i][j] = max(max(d[1][i][j], 
                             (m-j-1 ? a[i][j]+d[1][i][j+1] : -INF)),
                         max((i ? a[i][j]+d[0][i-1][j] : -INF),
                             (i ? a[i][j]+d[1][i-1][j] : -INF)));
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << d[0][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << d[1][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return max(d[0][n-1][m-1], d[1][n-1][m-1]);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            d[0][i][j] = d[1][i][j] = -INF;
        }
    cout << process();
    return 0;
}