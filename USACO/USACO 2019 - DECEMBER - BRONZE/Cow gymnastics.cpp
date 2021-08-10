#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 25;
int day, cow, pos[MAX][MAX];

bool check(int a, int b) {
	int nw = (pos[a][1] - pos[b][1]) / abs(pos[a][1] - pos[b][1]);
	for (int i = 2; i <= day; i++) {
		if ((pos[a][i] - pos[b][i]) * nw < 0) {
			return false;
		}
	}
	return true;
}

signed main() {
	cin >> day >> cow;
	for (int i = 1; i <= day; i++) {
		vector<int> c;
		for (int j = 1; j <= cow; j++) {
			int x; cin >> x;
			c.emplace_back(x);
		}
		for (int j = 0; j < c.size(); j++) {
			pos[c[j]][i] = j + 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= cow; i++) {
		for (int j = i + 1; j <= cow; j++) {
			if (check(i, j)) {
				ans++;
			}
		}
	}
	cout << ans;
}
