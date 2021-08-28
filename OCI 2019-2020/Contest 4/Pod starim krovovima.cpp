#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define real long double
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int> 
#define pii pair<int, ii>
#define ip pair<ii, int>  
int n; ip node[1005];
int result[1005];
signed main() {
    faster;
    cin >> n;
    int total = 0;
    for (int i= 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        total += u;
        node[i] = make_pair(ii(v, u), i);
    }
    sort(node + 1, node + 1 + n);
    for (int i = n; i >= 1; i--) {
        result[node[i].second] = min(total,node[i].first.first);
        total -= min(total, node[i].first.first);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (result[i] == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}
