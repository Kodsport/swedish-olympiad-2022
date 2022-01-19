#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tower {
	int x, f, h;
};
bool operator<(const Tower& a, const Tower& b) {
	return a.x < b.x;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int A, B, M;
	cin >> A >> B >> M;
	vector<Tower> towers;
	rep(i,0,A+B) {
		int x, f, h;
		cin >> x >> f >> h;
		if (i >= A) f *= -1;
		towers.push_back({x,f,h});
	}
	sort(all(towers));
	A += B;
	vector<pii> masts;
	rep(i,0,M) {
		int x, h;
		cin >> x >> h;
		masts.push_back({x,h});
	}
	const int inf = 5'000'000;
	masts.push_back({-inf, 0});
	masts.push_back({inf, 0});
	sort(all(masts), [&](pii a, pii b) {
		return a.first + a.second < b.first + b.second;
	});
	M += 2;

	vector<vi> scoreLeft(M, vi(A + 1));
	vector<vi> scoreRight(M, vi(A + 1));
	rep(i,0,M) {
		int mx = masts[i].first;
		int my = masts[i].second;
		int sum = 0;
		rep(j,0,A) {
			scoreRight[i][j] = sum;
			if (towers[j].x < mx) continue;
			int h = max(my - (towers[j].x - mx), 0);
			sum += min(towers[j].h, h) * towers[j].f;
		}
		scoreRight[i][A] = sum;
		sum = 0;
		for (int j = A - 1; j >= 0; j--) {
			if (towers[j].x >= mx) continue;
			int h = max(my - (mx - towers[j].x), 0);
			sum += min(towers[j].h, h) * towers[j].f;
			scoreLeft[i][j] = sum;
		}
	}

	vi dp(M);
	dp[0] = 0;
	rep(i,1,M) {
		int mx = masts[i].first;
		int my = masts[i].second;
		int best = INT_MIN;
		int k = A;
		for (int j = i-1; j >= 0; j--) {
			int ox = masts[j].first;
			int oy = masts[j].second;
			int dx = abs(mx - ox);
			int dy = abs(my - oy);
			if (dx <= dy) continue;
			assert(mx > ox);
			int midx = (mx + ox + oy - my + 1) >> 1;
			assert(ox <= midx);
			assert(midx <= mx);
			// j covers [ox, midx)
			// i covers [midx, mx)
			while (k - 1 >= 0 && towers[k - 1].x >= midx)
				k--;
			best = max(best, scoreRight[j][k] + scoreLeft[i][k] + dp[j]);
		}
		dp[i] = best;
	}
	cout << dp.back() << endl;
}
