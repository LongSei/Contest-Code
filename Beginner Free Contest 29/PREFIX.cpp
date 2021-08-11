#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string a, b;

signed main() {
    faster;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
