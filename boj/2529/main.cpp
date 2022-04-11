#include <bits/stdc++.h>
using namespace std;
char c[10];
char ans[10];
int n;

int process(int lev, set<int, less<int>>& S) {
    if (lev > n) return lev;
    if (c[lev] == '>') {
        int nextLev = process(lev + 1, S);
        cout << nextLev << endl;
    }
    int v = *S.begin();
    S.erase(v);
    cout << lev << " " << v << endl;
    if (c[lev] == '>') {

        //process(lev, S);
    }
    return lev;
}

int main() {
    set<int, less<int>> S;
    cin >> n;
    S.insert(0);
    for (int i = 0; i < n; i++) {
        S.insert(i + 1);
        cin >> c[i];
    }
    process(0, S);
    return 0;
}