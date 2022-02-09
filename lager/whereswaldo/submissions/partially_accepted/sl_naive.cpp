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
	rep(i,0,N) if (query(i, i + 1) == 1) return i;
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
