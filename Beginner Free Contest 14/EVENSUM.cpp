#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int n, arr[MAX];

signed main() {
    faster;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            ans += arr[i];
        }
    }
    cout << ans;
}
