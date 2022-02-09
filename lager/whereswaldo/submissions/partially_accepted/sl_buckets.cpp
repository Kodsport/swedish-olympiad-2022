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
	const int BUCKET_SIZE = 10;
	vector<tuple<ll, int, int>> buckets;
	for (int i = 0; i < N; i += BUCKET_SIZE) {
		int j = min(N, i + BUCKET_SIZE);
		buckets.push_back({query(i, j), i, j});
	}
	sort(all(buckets));
	for (auto b : buckets) {
		ll sum;
		int i, j;
		tie(sum, i, j) = b;
		rep(k,i,j-1) {
			ll s = query(k, k + 1);
			if (s == 1) return k;
			sum -= s;
		}
		if (sum == 1) return j-1;
	}
	assert(0);
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
