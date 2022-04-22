#include <bits/stdc++.h>
using namespace std;
int n;

struct compare {
    bool operator()(int x, int y) {
        if (abs(x) == abs(y)) return x > y;
        return abs(x) > abs(y);
    }
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    priority_queue<int, vector<int>, compare> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) {
            pq.push(x);
        } else if (pq.empty()) {
            cout << 0 << "\n";
        } else {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}