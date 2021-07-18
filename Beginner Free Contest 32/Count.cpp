#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ep emplace_back
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 200005;
vector<int> adjlist[MAX];
int n, colour[MAX];
set<int> node[MAX];
int real_node[MAX];
int ans[MAX];

void input() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjlist[u].ep(v);
		adjlist[v].ep(u);
	}
	for (int i = 1; i <= n; i++) {
		int u; cin >> u;
		colour[i] = u;
	}
}

void dfs(int pos, int parent) {
	node[pos].insert(colour[pos]);
	for (int v : adjlist[pos]) {
		if (v != parent) {
			dfs(v, pos);
			int rpos = real_node[pos];
			int rv = real_node[v];
			if (node[rpos].size() >= node[rv].size()) {
				for (auto v : node[rv]) {
					node[rpos].insert(v);
				}
			}
			else {
				real_node[pos] = real_node[v];
				for (auto v : node[rpos]) {
					node[rv].insert(v);
				}
			}
			ans[pos] = node[real_node[pos]].size();
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		real_node[i] = i;
		ans[i] = 1;
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}

signed main() {
	faster;
	input();
	solve();
}
