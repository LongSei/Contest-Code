#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int n, l, arr[MAX], prefix[MAX];

int binsearch(int value) {
	int l = 1, r = n;
	int res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (arr[mid] < value) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return res;
}

signed main() {
	faster;
	cin >> n >> l;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++) {
		int pos = binsearch(i);
		int upper = n - pos;
		if (upper >= i) {
			ans = max(ans, i);
			continue;
		}
		int pos2 = binsearch(i - 1);
		int add = pos - pos2;
		int remain = i - upper;
		if (remain > l) {
			continue;
		}
		if (remain <= add) {
			ans = max(ans, i);
		}
	}
	cout << ans;
}
