#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e6 + 5;
const int MAX2 = 1e3 + 5;
set<int> row[MAX];
int dp[MAX], n, q;

void solve() {
    int value; cin >> value;
    int ans = 0;
    for (int i = 0; i <= n + 1; i++) {
        dp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (row[i].find(value) != row[i].end()) {
            dp[i] = dp[i - 1] + 1;
        }
        else {
            dp[i] = 0;
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
}

signed main() {
    faster;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        for (int j = 1; j <= t; j++) {
            int k; cin >> k;
            row[i].insert(k);
        }
    }
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
