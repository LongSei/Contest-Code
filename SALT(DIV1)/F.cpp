#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
map<long long, vector<int> > checking;
map<long long, int> label;
set<long long> pos;
queue<long long> checking_pos;
const int MAX = 120;
const int mod = 1e9 + 7;
long long n;
int m, k;

struct mat {
	int x;
	int y;
	long long matrix[MAX][MAX];
} upmat[65];

void Add(long long &x, const long long &y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

mat operator * (const mat& a, const mat &b) {
	mat c;
	c.x = a.x;
	c.y = b.y;
	for (int i = 1; i <= c.x; i++) {
		for (int j = 1; j <= c.y; j++) {
			c.matrix[i][j] = 0ll;
		}
	}
	for (int i = 1; i <= c.x; i++) {
		for (int j = 1; j <= c.y; j++) {
			for (int k = 1; k <= a.y; k++) {
				c.matrix[i][j] += (b.matrix[k][j] * a.matrix[i][k] % mod);
			}
			c.matrix[i][j] %= mod;
		}
	}
	return c;
}

mat create_B(int n) {
	mat ret; n *= 2;
	ret.x = n; ret.y = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ret.matrix[i][j] = 0;
		}
	}
	for (int i = n / 2 + 1; i <= n; i++) {
		int id = i - (n / 2);
		ret.matrix[i][id] = 1;
	}
	for (int j = n / 2 + 1; j <= n; j++) {
		int id = j - (n / 2) + 1;
		if (id >= 1 && id <= n / 2) {
			ret.matrix[id][j] = 1;
		}
		if (id - 2 >= 1 && id - 2 <= n / 2) {
			ret.matrix[id - 2][j] = 1;
		}
		id = j + 2;
		if (id >= n / 2 + 1 && id <= n) {
			ret.matrix[id][j] = 1;
		}
		if (id - 4 >= n / 2 + 1 && id - 4 <= n) {
			ret.matrix[id - 4][j] = 1;
		}
	}
	return ret;
}

mat create_A(int n) {
	mat ret;
	ret.x = 1;
	ret.y = n * 2;
	n *= 2;
	for (int i = n / 2 + 1; i <= n; i++) {
		ret.matrix[1][i] = 1;
	}
	return ret;
}

void Matrix_Pow(mat& n, long long k) {
    k -= 1;
	while (k) {
        long long nw = (k & (-k));
        n = n * upmat[label[nw]];
        k -= nw;
    }
}

void create_adding_matrix(mat &T) {
    upmat[0] = T;
    upmat[1] = T * T;
    label[1] = 0;
    label[2] = 1;
    for (int i = 2; i <= 60; i++) {
        label[(1ll << i)] = i;
        upmat[i] = upmat[i - 1] * upmat[i - 1];
    }
}

void input() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		long long u;
		int v;
		cin >> u >> v;
		checking[u].push_back(v);		
		if (u == 1) {
			continue;
		}
		pos.insert(u);
	}
	pos.insert(n);
	for (auto v : pos) {
		checking_pos.push(v);
	}
}

void change_pos(mat& A, mat B, long long from, long long to) {
	long long timer = to - from;
	Matrix_Pow(B, timer);
	A = A * B;
}

void solve() {
	if (n == 1) {
		cout << m - k;
		return;
	}
	mat unit = create_B(m);
	mat beg = create_A(m);
    create_adding_matrix(unit);
	mat B = beg;
	if (checking[1].empty() == false) {
		for (auto v : checking[1]) {
			B.matrix[1][v + m] = 0;
		}
	}
	long long nw_pos = 1;
	while (checking_pos.empty() == false) {
		long long to_pos = checking_pos.front();
		checking_pos.pop();
		change_pos(B, unit, nw_pos, to_pos);
		for (auto v : checking[to_pos]) {
			B.matrix[1][v + m] = 0; 
		}
		nw_pos = to_pos;
	}
	long long res = 0;
	for (int i = m + 1; i <= 2 * m; i++) {
		res += B.matrix[1][i];
		res %= mod;
	}
	cout << res;
}

signed main() {
	faster;
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
	input();
	solve();
}
