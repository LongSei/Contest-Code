#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int a, b, x;

signed main() {
    cin >> a >> b >> x;
    x *= 3;
    cout << x - a - b;
}
