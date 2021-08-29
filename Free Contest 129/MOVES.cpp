#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define real long double
#define ii pair<int, int> 
#define pii pair<int, ii> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e3 + 5;
int arr[MAX], cost[MAX];
signed main() {
    faster;
    int test;
    cin >> test;
    while (test--) {
        int total = 0,n, maxi; cin >> n >> maxi;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            total += arr[i];
        }
        if (total <= (n + 1) / 2 * maxi) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
