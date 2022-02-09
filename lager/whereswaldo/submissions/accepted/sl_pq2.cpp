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

double score(int len, ll sum) {
	if (len == 1) return -1e10;
	return (double)sum / len; // (probably suboptimal)
}

int solve() {
	priority_queue<tuple<double, ll, int, int>> pq;
	ll totalSum = (ll)N * (N + 1) / 2;
	pq.push({0.0, totalSum, 0, N});
	set<int> seen;
	for (;;) {
		assert(!pq.empty());
		auto pa = pq.top();
		pq.pop();
		ll sum;
		int i, j;
		tie(ignore, sum, i, j) = pa;
		if (i + 1 == j) {
			if (sum == 1) return i;
			seen.insert((int)sum);
		} else {
			if (j - i == 2 && seen.count(sum - 1)) continue;
			if (sum > (ll)N * (j - i - 1) + 1) continue;
			// make left side size a power of two to make the pruning work slightly better (?)
			int left = (j - i) / 2;
			while (left & (left - 1)) left++;
			int mid = i + left;
			ll leftSum = query(i, mid), rightSum = sum - leftSum;
			pq.push({-score(mid - i, leftSum), leftSum, i, mid});
			pq.push({-score(j - mid, rightSum), rightSum, mid, j});
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	srand(5);
	int T;
	cin >> T >> N;
	query(0, 1 + rand() % N);
	rep(tc,0,T) {
		int r = solve();
		cout << "! " << r + 1 << endl;
	}
}
