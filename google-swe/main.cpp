#include <bits/stdc++.h>
#define M 100000
#define MOD 10007
using namespace std;
typedef long long ll;
int n, k;
ll m;
ll a[M+1];
ll inv[MOD+1];

ll inverse(ll x) {
	x %= MOD;
	if (x == 0) return 0;
	for (ll i = 1; i < MOD; i++) {
		if ((x*i) % MOD == 1) {
			return i;
		}
	}
}

int process() {
	ll mul = 1;
	int res = 0;
	// for (int i = 0; i < n; i++) 
	// 	cout << a[i] << " ";
	// cout << endl;
	// for (int i = 0; i < n; i++) 
	// 	cout << inverse(a[i]) << " ";
	// cout << endl;
	// cout << endl;
	for (int i = 0; i < k; i++) 
		mul = (mul*a[i]) % MOD;
	res += (mul == m);
	// cout << mul << " ";
	for (int i = k; i < n; i++) {
		if (a[i-k] == 0) {
			mul = 1;
			for (int j = 0; j < k; j++) 
				mul = (mul*a[i-j]) % MOD;
		}
		else {
			mul = (mul*a[i]) % MOD;
			mul = (mul*inv[a[i-k]]) % MOD;
		}
		// cout << mul << " ";
		res += (mul == m);
	}
	// cout << endl;
	return res;

}

int main() {
	int T; cin >> T;
	for (int i = 1; i < MOD; i++) {
		inv[i] = inverse(i);
	}
	for (int t = 1; t <= T; t++) {
		cin >> n >> k >> m;
		ll ai;
		for (int i = 0; i < n; i++) {
			cin >> ai;
			a[i] = ai % MOD;
		}
		cout << process() << endl;
	}
	return 0;
}