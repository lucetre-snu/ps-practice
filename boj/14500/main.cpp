#include <bits/stdc++.h>
#define M 500
using namespace std;
int a[M + 1][M + 1];
int n, m;

typedef struct {
    int r = 0;
    int c = 0;
    vector<int> dy;
    vector<int> dx;

    void push(int y, int x) {
        r = max(r, y + 1);
        c = max(c, x + 1);
        dy.push_back(y);
        dx.push_back(x);
    }
} tet;

vector<tet> vt;


void init() {
    tet t1, t2;
    for (int i = 0; i < 4; i++) {
        t1.push(i, 0);
        t2.push(0, i);
    }
    vt.push_back(t1);
    vt.push_back(t2);

    tet t3;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            t3.push(i, j);
        }
    }
    vt.push_back(t3);

    tet t4, t5, t6, t7;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            t4.push(i, j + i);
            t5.push(j + i, i);
            t6.push(i, j + 1 - i);
            t7.push(j + 1 - i, i);
        }
    }
    vt.push_back(t4);
    vt.push_back(t5);
    vt.push_back(t6);
    vt.push_back(t7);

    tet t8, t9, t10, t11;
    for (int i = 0; i < 3; i++) {
        t8.push(0, i);
        t9.push(1, i);
        t10.push(i, 0);
        t11.push(i, 1);
    }

    for (int i = 0; i < 3; i++) {
        tet t = t8;
        t.push(1, i);
        vt.push_back(t);
    }
    for (int i = 0; i < 3; i++) {
        tet t = t9;
        t.push(0, i);
        vt.push_back(t);
    }
    for (int i = 0; i < 3; i++) {
        tet t = t10;
        t.push(i, 1);
        vt.push_back(t);
    }
    for (int i = 0; i < 3; i++) {
        tet t = t11;
        t.push(i, 0);
        vt.push_back(t);
    }

}

int process() {
    int ans = 0;
    for (auto t : vt) {
        for (int i = 0; i <= n - t.r;i++) {
            for (int j = 0; j <= m - t.c; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    int ty = i + t.dy[k];
                    int tx = j + t.dx[k];
                    sum += a[ty][tx];
                }
                ans = max(ans, sum);
            }
        }

        // cout << "(" << t.r << "," << t.c << ")" << endl;
        // for (int i = 0; i < 4; i++) {
        //     cout << t.dy[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < 4; i++) {
        //     cout << t.dx[i] << " ";
        // }
        // cout << endl;
    }
    return ans;

}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << process();
    return 0;
}