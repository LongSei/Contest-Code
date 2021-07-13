#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 5e5 + 5;
int n, m, ans = 0;
vector<int> adjlist[MAX];
int colour[MAX], number_colour[MAX];
bool checking = false;

void dfs(int pos, int parent) {
	number_colour[pos] = colour[pos];
	for (int v : adjlist[pos]) {
		if (v != parent) {
			if (colour[v] == colour[pos] && colour[pos] == 1) {
				checking = true;
			}
			dfs(v, pos);
			number_colour[pos] += number_colour[v];
		}
	}
	if (number_colour[pos] >= 2) {
		if (colour[pos] == 1) {
			ans += number_colour[pos] - 1;
			number_colour[pos] = 1;
		}
		else {
			ans += 1;
			number_colour[pos] = 0;
		}
	}
}

signed main() {
	faster;
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjlist[v].emplace_back(u);
		adjlist[u].emplace_back(v);
	}
	for (int i = 1; i <= m; i++) {
		int u; cin >> u;
		colour[u] = 1;
	}
	dfs(1, -1);
	if (checking == true) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}