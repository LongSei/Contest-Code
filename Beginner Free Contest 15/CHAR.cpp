#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
    faster;
    char x; cin >> x;
    char ans = x + 1;
    if (ans > 122) {
        cout << 'a';
    }
    else {
        cout << ans;
    }
}
