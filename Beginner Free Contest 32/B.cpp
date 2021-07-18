#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ep emplace_back
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 60;
int board[MAX][MAX], n;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		cout << ceil(sqrt(board[i][i])) << " ";
	}
}

signed main() {
	faster;
	input();
	solve();
}
