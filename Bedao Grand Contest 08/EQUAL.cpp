#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define real long double
#define ii pair<int, int> 
#define pii pair<int, ii> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e6 + 5;
int isPrime[MAX];
int gcd(int a, int b) {return a % b == 0 ? b : gcd(b, a % b);}

void create() {
    for (int i = 2; i <= MAX - 5; i++) {
        if (isPrime[i] == 0) {
            isPrime[i] = i;
            int q = 2 * i;
            while (q <= MAX - 5) {
                isPrime[q] = i;
                q += i;
            }
        }
    }
}

int calc(int n) {
    int res = 0;
    while (n > 1) {
        n /= isPrime[n];
        res++;
    }
    return res;
}

signed main() {
    create();
    int test; cin >> test;
    while (test--) {
        int a, b; cin >> a >> b;
        int el = gcd(a, b);
        cout << max(calc(a / el), calc(b / el)) << endl;
    }
}
