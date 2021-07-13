#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9 + 7;
int test;

int mul(int a, int b) {
	if (a % 2 == 0) {
		a /= 2;
	}
	else if (b % 2 == 0) {
		b /= 2;
	}
	b %= mod;
	a %= mod;
	return (a * b) % mod;
}

void solve() {
	int l, r, n;
	cin >> l >> r >> n;
	int number_can_divide = (r / n) - ((l - 1) / n);
	int number_pair = mul((r - l + 1), (r - l + 2));
	int number_pair_w = mul(number_can_divide, (number_can_divide + 1));
	cout << (number_pair - number_pair_w + mod) % mod << endl;
}

signed main() {
	faster;
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
}
