#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
int arr[5];

signed main() {
    for (int i = 1; i <= 4; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + 3);
    if (arr[3] - arr[1] <= arr[4]) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}
