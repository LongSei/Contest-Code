#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ep emplace_back
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1005;
char board[MAX][MAX];
int n, m;
int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};
int sum = 0;
bool check[MAX][MAX];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
}

int isok(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m && board[x][y] == '#') {
		return 1;
	}
	return 0;
}

int fin(int x, int y) {
	int res = 0;
	for (int i = 0; i < 8; i++) {
		res += isok(x + dx[i], y + dy[i]);
	}
	return res;
}

void solve() {
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] != '.') {
				sum += fin(i, j);
			}
			else {
				maxi = max(maxi, fin(i, j));
			}
		}
	}
	cout << sum / 2 + maxi;
}

signed main() {
	faster;
	input();
	solve();
}
