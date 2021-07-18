#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 105;
typedef pair<int, int> ii;
int timer = 0, n, m, k;
int check[MAX][MAX], board[MAX][MAX];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool isok(int x, int y) {
	if (x >= 1 && y >= 1 && x <= n && y <= m) {
		return true;
	}
	return false;
}

ii move(int x, int y, int way) {
	int nx = x + dx[way];
	int ny = y + dy[way];
	if (isok(nx, ny) == false) {
		return ii(x, y);
	}
	return ii(nx, ny);
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	cin >> k;
}

void solve() {
	ii nw = ii(1, 1);
	check[1][1] = 1;
	int x = 1; 
	int y = 1;
	int flag = 0;
	while (k > 0) {
		k--;
		ii nw = move(x, y, board[x][y]);
		if (isok(nw.first, nw.second) == false) {
			break;
		}
        if (!flag && check[nw.first][nw.second]) k %= (check[x][y] - check[nw.first][nw.second] + 1), flag = 1;
        if (!flag && !check[nw.first][nw.second]) check[nw.first][nw.second] = check[x][y] + 1;
		x = nw.first;
		y = nw.second;
	}
	cout << x << " " << y;
}

signed main() {
	faster;
	input();
	solve();
}
