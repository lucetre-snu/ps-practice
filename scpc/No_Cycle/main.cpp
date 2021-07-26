#include <bits/stdc++.h>
#define M 500
#define K 2000
using namespace std;
int n, m, k;
vector<int> v[M+1];
bool val[M+1][M+1];
pair<int, int> p[K+1];
int c[M+1], flag;
int visit[M+1];

bool isCyclic(int srt, int k) {
    if (visit[k]) {
        if (srt == k)
            return true;
        return false;
    }
    visit[k] = true;
    for (int i = 0; i < v[k].size(); i++)
        if (val[k][v[k][i]])
            if (isCyclic(srt, v[k][i]))
                return true;
    return false;
}

void process(int lev) {
    if (flag) return;
    if (lev == k) {
        memset(visit, 0, n*sizeof(int));
        if (isCyclic(0, 0)) return;
        flag = 1;
        for (int i = 0; i < k; i++) 
            cout << c[i];
        cout << endl;
        return;
    }
    c[lev] = 0;
    val[p[lev].first][p[lev].second] = 1;
    process(lev+1);
    c[lev] = 1;
    val[p[lev].first][p[lev].second] = 0;
    val[p[lev].second][p[lev].first] = 1;
    process(lev+1);
    val[p[lev].second][p[lev].first] = 0;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        flag = 0;
        cout << "Case #" << t << endl;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                val[i][j] = 0;
            v[i] = vector<int>();
        }
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            v[x-1].push_back(y-1);
            val[x-1][y-1] = 1;
        }
        for (int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            v[x-1].push_back(y-1);
            v[y-1].push_back(x-1);
            p[i] = make_pair(x-1, y-1);
        }
        process(0);
    }
    return 0;
}