#include <bits/stdc++.h>
#define M 500
using namespace std;
vector<pair<int, int>> a[M*2+1];
bool visit[M*2+1];
int key[M*2+1];
int n;

int process() {
    priority_queue<pair<int, int>> Q;
    for (int i = 0; i < 2*n; i++) {
        key[i] = visit[i] = 0;
        Q.push(make_pair(0, i));
    }
    
    while (! Q.empty()) {
        int f = Q.top().second; Q.pop();
        visit[f] = true;
        for (int i = 0; i < a[f].size(); i++) {
            int v = a[f][i].first;
            int cost = a[f][i].second;
            if (!visit[v] && key[v] < cost) {
                key[v] = cost;
                Q.push(make_pair(cost, v));
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 2*n; i++) {
        res += key[i];
        // cout << key[i] << " ";
    }
    // cout << endl;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    int c[M+1][M+1];
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int res = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> c[i][j];
            a[i] = vector<pair<int, int>>();
            a[i+n] = vector<pair<int, int>>();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cost;
                cin >> cost;
                res += cost;
                if (c[i][j] == -1) {
                    a[i].push_back(make_pair(n+j, cost));
                    a[n+j].push_back(make_pair(i, cost));
                }
            }
        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> c[i][j];
        cout << "Case #" << t << ": ";
        cout << res - process() << endl;
    }
}
