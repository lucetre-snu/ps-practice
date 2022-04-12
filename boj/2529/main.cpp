#include <bits/stdc++.h>
using namespace std;
char C[10];
int n;

void process2() {
    set<int, less<int>> S;
    for (int i = 0; i <= n; i++) {
        S.insert(i);
    }
    
    stack<int> ST;
    int val = *S.begin();
    S.erase(val);
    ST.push(val);
    
    for (int i = 0; i < n; i++) {
        if (C[i] == '>') {
            int val = *S.begin();
            S.erase(val);
            ST.push(val);
        } else if (C[i] == '<') {
            bool flag = true;
            while (!ST.empty()) {
                flag = false;
                int val = ST.top(); ST.pop();
                cout << val;
            }
            if (flag) {
                int val = *S.begin();
                S.erase(val);
                cout << val;
            } else {
                int val = *S.begin();
                S.erase(val);
                ST.push(val);
            }
        }
    }
    
    while (!ST.empty()) {
        int val = ST.top(); ST.pop();
        cout << val;
    }
    while (!S.empty()) {
        int val = *S.begin();
        S.erase(val);
        cout << val;
    }
}


void process1() {
    set<int, greater<int>> S;
    for (int i = 0; i <= n; i++) {
        S.insert(9-i);
    }
    
    stack<int> ST;
    
    int val = *S.begin();
    S.erase(val);
    ST.push(val);
    
    for (int i = 0; i < n; i++) {
        if (C[i] == '<') {
            int val = *S.begin();
            S.erase(val);
            ST.push(val);
        } else if (C[i] == '>') {
            bool flag = true;
            while (!ST.empty()) {
                flag = false;
                int val = ST.top(); ST.pop();
                cout << val;
            }
            if (flag) {
                int val = *S.begin();
                S.erase(val);
                cout << val;
            } else {
                int val = *S.begin();
                S.erase(val);
                ST.push(val);
            }
        }
    }
    
    while (!ST.empty()) {
        int val = ST.top(); ST.pop();
        cout << val;
    }
    while (!S.empty()) {
        int val = *S.begin();
        S.erase(val);
        cout << val;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    process1();
    cout << endl;
    process2();
    return 0;
}