#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 5010;
const double eps = 1e-6;

int n, m;
int a[N];

int solve(int l, int r, int last) {
	if (l == r) return 1;
	int minv = 1e9;
	for (int i = l; i <= r; i ++) minv = min(minv, a[i]);

	long long ans = r - l + 1, cnt = 0;
	long long cur = 0;
	cnt += minv - last;

	int fi = l, la = l;
	for (int k = l; k <= r; k ++) {
		if (a[k] <= minv) {
			if (la == fi) {
				if (a[la] > minv) cnt ++;
			}
			else {
				cur += solve(fi, la, minv);
			}
			fi = la = k + 1;
		}
		else la = k;
	}
	if (la <= r && fi <= r) {
		if (la == fi) {
			if (a[la] > minv) cnt ++;
		}
		else {
			cur += solve(fi, la, minv);
		}
	}
	ans = min(ans, cnt + cur);
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	cout << solve(1, n, 0) << endl;

	return 0;
}