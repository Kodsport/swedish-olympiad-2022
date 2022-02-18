// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 1'000'000'007;
const int P = 239;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

void solve() {
	int k, n;
	cin >> k >> n;
	vector<vector<bool>> can(k, vector<bool>(k));
	for (int i = 0; i < k; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < k; ++j) {
			can[i][j] = s[j] == '1';
		}
	}
	string s;
	cin >> s;
	vector<int> arr;
	for (char c : s) {
		arr.push_back(c - 'a');
	}

	s += '!';

	vector<int> pp = {1};
	for (int i = 0; i < n + 5; ++i) {
		pp.push_back(mult(pp.back(), P));
	}

	vector<pii> st = {{n, n}};
	vector<int> depth(n + 1);
	int bp = 1;
	while (1 << bp < n) {
		bp++;
	}
	vector<vector<pii> > binup(n + 1, vector<pii>(bp));
	for (int i = 0; i < bp; ++i) {
		binup[n][i] = {n, 0};
	}

	auto is_less = [&](int a, int b) {
		for (int i = bp - 1; i >= 0; --i) {
			if (depth[a] >= (1 << i) && depth[b] >= (1 << i) && binup[a][i].ss == binup[b][i].ss) {
				a = binup[a][i].ff;
				b = binup[b][i].ff;
			}
		}
		return s[a] < s[b];
	};

	for (int i = n - 1; i >= 0; --i) {
		while (szof(st) > 1) {
			if (can[arr[i]][arr[st.back().ff]]) {
				int tmp = st.back().ss;
				st.pop_back();
				if (is_less(tmp, st.back().ss)) {
					st.back().ss = tmp;
				}
			} else {
				break;
			}
		}

		depth[i] = depth[st.back().ss] + 1;
		binup[i][0] = {st.back().ss, s[i]};

		for (int j = 1; j < bp; ++j) {
			int h1 = binup[i][j - 1].ss;
			int v = binup[i][j - 1].ff;
			int h2 = binup[v][j - 1].ss;
			binup[i][j] = {binup[v][j - 1].ff, sum(mult(h1, pp[1 << (j - 1)]), h2)};
		}

		st.push_back({i, i});
	}

	string ans = "";

	int v = 0;
	while (v != n) {
		ans += s[v];
		v = binup[v][0].ff;
	}

	cout << ans << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}