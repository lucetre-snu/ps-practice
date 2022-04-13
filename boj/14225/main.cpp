#include <bits/stdc++.h>
#define M 20
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;
int a[M + 1];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 1 << n; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            bool flag = i & (1 << j);
            sum += flag ? a[j] : 0;
        }
        pq.push(sum);
    }
    long long prev = -1;
    while (!pq.empty()) {
        long long f = pq.top();
        pq.pop();
        if (f - prev <= 1) {
            prev = f;
            continue;
        }
        else {
            cout << prev + 1;
            exit(0);
        }
    }
    cout << (1 << n);
    return 0;
}