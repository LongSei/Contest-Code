#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2005;
const int INF = 1e9 + 7;
typedef pair<int, int> ii;
int dp[MAX][MAX], must_use[MAX][MAX];
int pos;
string s; int n;
struct po {
	int t, p, m, d;
};
po numb[2][MAX];

void debug_muse_use() {
	for (int i = 0; i <= n + 1; i++) {
		for (int j = i; j <= n + 1; j++) {
			cout << i << " " << j << " " << must_use[i][j] << endl;
		}
	}
}

void debug_dp() {
	for (int i = 0; i <= n + 1; i++) {
		for (int j = i; j <= n + 1; j++) {
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
}

void reset() {
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			dp[i][j] = INF;
			must_use[i][j] = INF;
		}
	}
}

void findingpos() {
	for (int i = 1; i <= n; i++) {
		if (s[i] == '#') {
			pos = i;
		}
	}
}

int count(int l, int r, char x) {
	int res = 0;
	for (int i = l; i <= r; i++) {
		if (s[i] == x) {
			res++;
		}
	}
	return res;
}

void create() {
	for (int i = 0; i <= n + 1; i++) {
		numb[0][i].t = count(1, 1 + i - 1, 'T');
		numb[0][i].p = count(1, 1 + i - 1, 'P');
		numb[0][i].m = count(1, 1 + i - 1, 'M');
		numb[0][i].d = count(1, 1 + i - 1, 'D');
		numb[1][i].t = count(1 + i - 1, s.size() - 1, 'T');
		numb[1][i].p = count(1 + i - 1, s.size() - 1, 'P');
		numb[1][i].m = count(1 + i - 1, s.size() - 1, 'M');
		numb[1][i].d = count(1 + i - 1, s.size() - 1, 'D');
	}
}

int f(int type, int index, char x) {
	if (x == 'T') {
		return numb[type][index].t;
	}
	if (x == 'P') {
		return numb[type][index].p;
	}
	if (x == 'M') {
		return numb[type][index].m;
	}
	if (x == 'D') {
		return numb[type][index].d;
	}
	return 0;
}

int fin(char x, int l, int r) {
	if (l == r) {
		return f(0, l, x) + f(1, r, x);
	}
	return f(0, l, x) + f(1, r, x);
}

bool checking(int l, int r) {
	if (fin('D', l, r) + fin('T', l, r) >= fin('M', l, r) && s[l] != '#' && s[r] != '#') {
		return true;
	}
	return false;
}

bool fuse(int l, int r, int nw) {
	if (fin('D', l, r) < fin('M', l, r) - nw) {
		return true;
	}
	return false;
}

void create_must_use() {
	must_use[0][n + 1] = 0;
	for (int l = 0; l <= n + 1; l++) {
		for (int r = n + 1; r >= 0 && r >= l; r--) {
			if (must_use[l][r] == INF) {
				continue;
			}
			if (checking(l + 1, r) == true) {
				if (fuse(l + 1, r, must_use[l][r]) == true) {
					must_use[l + 1][r] = min(must_use[l + 1][r], must_use[l][r] + 1);
				}
				else {
					must_use[l + 1][r] = min(must_use[l][r], must_use[l + 1][r]);
				}
			}
			if (checking(l, r - 1) == true) {
				if (fuse(l, r - 1, must_use[l][r]) == true) {
					must_use[l][r - 1] = min(must_use[l][r - 1], must_use[l][r] + 1);
				}
				else {
					must_use[l][r - 1] = min(must_use[l][r], must_use[l][r - 1]);
				}
			}
		}
	}
}

void create_dp() {
	for (int l = 0; l <= n + 1; l++) {
		for (int r = l; r <= n + 1; r++) {
			if (must_use[l][r] == INF) {
				continue;
			}
			int t = fin('T', l, r);
			int p = fin('P', l, r);
			int d = fin('D', l, r);
			int m = fin('M', l, r);
			t -= must_use[l][r];
			m -= must_use[l][r];
			int remain = d - m;
			if (remain < 0) {
				remain += min(min(m, t), abs(remain));
			}
			if (remain > 0) {
				remain -= min(min(d, p), remain);
			}
			dp[l][r] = remain;
		}
	}
}

void solve() {
	cin >> s;
	s = " " + s;
	n = s.size() - 1;
	findingpos();
	reset();
	create();
	create_must_use();
	create_dp();
	int ans = INF;
	for (int i = 0; i <= pos - 1; i++) {
		ans = min(ans, dp[i][pos + 1]);
	}
	for (int i = pos + 1; i <= n + 1; i++) {
		ans = min(ans, dp[pos - 1][i]);
	}
	if (ans == INF || ans < 0) {
		cout << "LOSE" << endl;
		return;
	}
	cout << ans << endl;
}

signed main() {
	faster;
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
}