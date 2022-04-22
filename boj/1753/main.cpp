#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define M 20000
int V, E, K;
vector<pair<int, int>> adj[M+1];
int a[M+1];

void process() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < V; i++) {
        a[i] = INF;
    }
    a[K-1] = 0;
    pq.push(make_pair(0, K-1));
    while (!pq.empty()) {
        pair<int, int> f = pq.top(); pq.pop();
        for (int i = 0; i < adj[f.second].size(); i++) {
            int v = adj[f.second][i].first;
            int c = adj[f.second][i].second;
            if (a[v] > f.first + c) {
                a[v] = f.first + c;
                pq.push(make_pair(f.first + c, v));
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (a[i] == INF) cout << "INF\n";
        else cout << a[i] << "\n";
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x-1].push_back(make_pair(y-1, z));
    }
    process();

    return 0;
}