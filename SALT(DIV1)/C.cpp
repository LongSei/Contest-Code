#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 5005;
const int mod = 1e9 + 7;
int dp[MAX][MAX], total = 0, real_prefix_sum[MAX], prefix_sum[MAX], arr[MAX], all_last[MAX];
// dp[i][j]: to finish j and to level i
// prefix[i]: sub if you choose i in this level
// real_prefix[i]: all finish level with i you choose
// all[i]: all dp in level i
int n, k;

void solve() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[1][i] = arr[i];
		all_last[1] += dp[1][i];
	}
	for (int level = 2; level <= k; level++) {
		for (int i = 1; i <= n; i++) {
			dp[level][i] = arr[i] * ((all_last[level - 1] - dp[level - 1][i]) % mod) % mod;
			all_last[level - 1] -= dp[level - 1][i];
			all_last[level] += dp[level][i];
			if (all_last[level - 1] == 0) {
				break;
			}
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		ans += dp[k][i];
		ans %= mod;
	}
	cout << ans;
}

signed main() {
	faster;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	solve();
}