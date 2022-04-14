#include <bits/stdc++.h>
#define M 10000
using namespace std;
int c[M + 1];
pair<char, int> p[M + 1];
int a, b;

void backtracking(int x) {
    if (c[x]) {
        backtracking(p[x].second);
        cout << p[x].first;
    }
}

void process() {
    for (int i = 0; i < M; i++) {
        c[i] = -1;
    }
    c[a] = 0;
    p[a] = make_pair(NULL, NULL);
    queue<int> Q;
    Q.push(a);
    while (!Q.empty()) {
        int f = Q.front(); Q.pop();
        // D
        int D = (f * 2) % M;
        if (c[D] == -1) {
            Q.push(D);
            c[D] = c[f] + 1;
            p[D] = make_pair('D', f);
        }
        // S
        int S = (f - 1 + M) % M;
        if (c[S] == -1) {
            Q.push(S);
            c[S] = c[f] + 1;
            p[S] = make_pair('S', f);
        }
        // L
        int L = (f * 10 / M) + (f * 10 % M);
        if (c[L] == -1) {
            Q.push(L);
            c[L] = c[f] + 1;
            p[L] = make_pair('L', f);
        }
        // R
        int R = ((f % 10) * M + f) / 10;
        if (c[R] == -1) {
            Q.push(R);
            c[R] = c[f] + 1;
            p[R] = make_pair('R', f);
        }
    }
    backtracking(b);
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> a >> b;
        process();
        cout << endl;
    }
    return 0;
}