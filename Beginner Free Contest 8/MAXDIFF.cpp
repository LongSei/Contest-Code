#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1005;
int n, arr[MAX];

signed main() {
    faster;
    cin >> n;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 2; i <= n; i++) {
        ans = max(ans, arr[i] - arr[i - 1]);
        if (i >= 3) {
            ans = max(ans, arr[i] - arr[i - 2]);
        }
    }
    cout << ans;
}
