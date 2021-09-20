#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e4 + 5;
int n, len[MAX];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> len[i];
    }
    if (len[1] == 1 && n >= 2) {
        cout << -1 << endl;
        return;
    }
    if (len[1] == 1 && n == 1) {
        cout << "z" << endl;
        return;
    }
    string res = "z";
    len[1] -= 1;
    for (int i = 1; i <= n; i++) {
        int last;
        if (i % 2 == 0) {
            last = 1;
            int nw = 1;
            while (nw < len[i]) {
                if (last < 0 || last > 25) {
                    cout << -1 << endl;
                    return;
                }
                res += 'a' + last; last++; nw++;
            }
            if (i < n) {
                last = max(last, len[i + 1]);
            }
            if (last < 0 || last > 25) {
                cout << -1 << endl;
                return;
            }
            res += 'a' + last;
        }
        else {
            last = len[i] - 1;
            int nw = 1;
            while (nw <= len[i]) {
                if (last < 0 || last > 25) {
                    cout << -1 << endl;
                    return;
                }
                res += 'a' + last; last--; nw++;
            }
        }
    }
    cout << res << endl;
}

signed main() {
    faster;
    int test; cin >> test;
    while (test--) {
        solve();
    }
}
