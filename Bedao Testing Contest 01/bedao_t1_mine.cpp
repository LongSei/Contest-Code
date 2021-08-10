#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e6 + 5;
int board[MAX];

signed main() {
    faster;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> board[i];
    }
    for (int i = 1; i <= n * m; i++) {
        cout << 1 - board[i] << " ";
        if (i % m == 0) {
            cout << endl;
        }
    }
}
