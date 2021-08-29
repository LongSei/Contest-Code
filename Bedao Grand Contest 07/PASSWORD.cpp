#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define real long double
#define ii pair<int, int> 
#define pii pair<int, ii> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e6 + 5;
int arr[MAX], n;

signed main() {
    faster;
    cin >> n;
    int res = -1000000007;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        res = max(res, arr[i]);
    }
    cout << res;
}
