#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ep emplace_back
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
int arr[MAX], n;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	int nw = 1e9 + 7;
	int sum = 0;
	for (int i = n; i >= 1; i--) {
		if (min(arr[i], nw - 1) <= 0) {
			continue;
		}
		nw = min(arr[i], nw - 1);
		sum += nw;
	}
	cout << sum;
}

signed main() {
	faster;
	input();
	solve();
}
