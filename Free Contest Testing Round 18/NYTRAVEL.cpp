#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define real long double
#define ii pair<int, int> 
#define pii pair<int, ii> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 100005;
int pset[MAX], setsize[MAX];
int n, m;

void init(int k) {
    for (int i = 1; i <= k; i++) {
        pset[i]  =i;
        setsize[i] = 1;
    }
}

int findset(int i) {
    if (pset[i] == i) {
        return i;
    }
    return pset[i] = findset(pset[i]);
}

bool issameset(int i, int j) {
    return findset(i) == findset(j);
}

void unionset(int i, int j) {
    i = findset(i);
    j = findset(j);
    pset[i] = pset[j];
    setsize[j] += setsize[i];
}

signed main() {
    faster;
    int n, m; cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (issameset(u, v) == false) {
            unionset(u, v);
        }
    }
    int res = setsize[findset(1)];
    int maxi = 0;
    for (int i = 1; i <= n; i++) {
        if (issameset(1, i) == false) {
            maxi = max(maxi, setsize[findset(i)]);
        }
    }
    cout << maxi + res;
}
