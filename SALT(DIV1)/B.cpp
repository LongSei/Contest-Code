#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9 + 7;

int sum(int a, int b) {
	if (a % 2 == 1) {
		b /= 2;
	}
	else {
		a /= 2;
	}
	a %= mod;
	b %= mod;
	return a * b;
}

int multi(int a, int b) {
	a %= mod;
	b %= mod;
	int res = a * b;
	return res % mod;
}

int spec(int n) {
	int a = n;
	int b = n + 1;
	int c = a + b;
	if (a % 2 == 0) {
		a /= 2;
	}
	else if (b % 2 == 0) {
		b /= 2;
	}
	else if (c % 2 == 0) {
		c /= 2;
	}
	if (a % 3 == 0) {
		a /= 3;
	}
	else if (b % 3 == 0) {
		b /= 3;
	}
	else if (c % 3 == 0) {
		c /= 3;
	}
	a %= mod;
	b %= mod;
	c %= mod;
	return ((a * b) % mod * c) % mod;
}

int f(int n) {
	int a = n + 1;
	int b = sum(n, n + 1);
	int c = spec(n);
	return (multi(a, b) - c + mod) % mod;
}

int ch(int x, int y, int z) {
	int for_a = sum(x, (x + 1));
	int for_b = sum(y, (y + 1));
	int for_c = sum(z, (z + 1));
	z = multi(multi(for_b, for_a), (f(z)));
	y = multi(multi(for_c, for_a), (f(y)));
	x = multi(multi(for_b, for_c), (f(x)));
	return (x + y + z) % mod;
}

int area(int x, int y, int z) {
	return multi(multi(f(x), f(y)), f(z));
}

int full_area(int x, int y, int z) {
	int for_a = sum(x, (x + 1));
	int for_b = sum(y, (y + 1));
	int for_c = sum(z, (z + 1));
	int nz = multi(multi(for_b, f(x)),(f(z)));
	int ny = multi(multi(for_c, f(x)),(f(y)));
	int nx = multi(multi(for_a, f(z)),(f(y)));
	return (nx + ny + nz) % mod;	
}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << area(a, b, c) << " " << multi(ch(a, b, c), 4) << " " << multi(full_area(a, b, c), 2) << endl;
}

signed main() {
	faster;
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
}