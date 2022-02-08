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

void rec(int L, int R, ll sum) {
	if (L + 1 == R) {
		if (sum == 1) throw L;
	} else {
		int mid = (L + R) / 2;
		ll leftSum = query(L, mid), rightSum = sum - leftSum;
		if (leftSum < rightSum) {
			rec(L, mid, leftSum);
			rec(mid, R, rightSum);
		} else {
			rec(mid, R, rightSum);
			rec(L, mid, leftSum);
		}
	}
}

int solve() {
	ll sum = (ll)N * (N+1) / 2;
	try {
		rec(0, N, sum);
		assert(0);
	} catch (int x) {
		return x;
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
