#include <bits/stdc++.h>
#define M 100000
#define N (1<<18)
typedef long long ll;
using namespace std;
int n, q;
vector<pair<int, pair<int, ll>>> a[M+1];
vector<pair<int, int>> query[M+1];
ll tree[2*N];
ll answer[M+1];

void dfs(int v, int parent) {
    for (int i = 0; i < query[v].size(); i++) {
        int l = query[v][i].second;
        ll g = tree[N + l];
        for (int x = N+l; x > 1; x /= 2)
            if (x % 2) g = __gcd(g, tree[x-1]);
        answer[query[v][i].first] = g;
    }
    
    for (int i = 0; i < a[v].size(); i++) {
        if (a[v][i].first == parent) continue;
        
        int u = a[v][i].first;
        int l = a[v][i].second.first;

        tree[N+l] = a[v][i].second.second;
        for (int x = (N+l)/2; x >= 1; x /= 2)
            tree[x] = __gcd(tree[2*x], tree[2*x+1]);

        dfs(u, v);
        tree[N+l] = 0;
        for (int x = (N+l)/2; x >= 1; x /= 2) 
            tree[x] = __gcd(tree[2*x], tree[2*x+1]);
    }
}

void process() {
    dfs(0, -1);
    for (int i = 0; i < q; i++)
        cout << answer[i] << " ";
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> q;
        for (int i = 0; i < 2*N; i++) {
            tree[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            a[i] = vector<pair<int, pair<int, ll>>>();
            query[i] = vector<pair<int, int>>();
        }
        for (int i = 0; i < n-1; i++) {
            int x, y, li;
            ll ai;
            cin >> x >> y >> li >> ai;
            a[x-1].push_back(make_pair(y-1, make_pair(li, ai)));
            a[y-1].push_back(make_pair(x-1, make_pair(li, ai)));
        }
        for (int i = 0; i < q; i++) {
            answer[i] = 0;
            int v, w;
            cin >> v >> w;
            query[v-1].push_back(make_pair(i, w));
        }
        cout << "Case #" << t << ": ";
        process();
    }
    return 0;
}