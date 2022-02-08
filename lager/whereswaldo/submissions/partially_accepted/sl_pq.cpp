#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;

ll query(int L, int R) {
	assert(L < R);
	cout << "? " << L + 1 << ' ' << R << endl;
	ll res;
	cin >> res;
	return res;
}

int solve() {
	priority_queue<tuple<double, ll, int, int>> pq;
	ll totalSum = (ll)N * (N + 1) / 2;
	pq.push({-(double)totalSum / N, totalSum, 0, N});
	for (;;) {
		assert(!pq.empty());
		auto pa = pq.top();
		pq.pop();
		ll sum;
		int i, j;
		tie(ignore, sum, i, j) = pa;
		if (i + 1 == j) {
			if (sum == 1) return i;
		} else {
			int mid = (i + j) / 2;
			ll leftSum = query(i, mid), rightSum = sum - leftSum;
			pq.push({-(double)leftSum / (mid - i), leftSum, i, mid});
			pq.push({-(double)rightSum / (j - mid), rightSum, mid, j});
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T >> N;
	rep(tc,0,T) {
		int r = solve();
		cout << "! " << r + 1 << endl;
	}
}
