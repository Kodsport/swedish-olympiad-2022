#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main(int argc, char **argv) {
	init_io(argc, argv);

	ll T, N;
	judge_in >> T >> N;

	cout << T << ' ' << N << endl;

	unsigned int hash = 1;
    mt19937 rng(815262975);

	vector<ll> perm(N), sumTo(N + 1);
	for (int i = 0; i < N; i++) perm[i] = i + 1;

	ll queries = 0;
	for (int i = 0; i < T; i++) {
		mt19937 rng2(rng() ^ hash);
		shuffle(perm.begin(), perm.end(), rng2);
		sumTo[0] = 0;
		for (int i = 0; i < N; i++) sumTo[i+1] = sumTo[i] + perm[i];
		int answer = (int)(find(perm.begin(), perm.end(), 1) - perm.begin()) + 1;
		for (;;) {
			char que;
			cin >> que;
			if (!cin) wrong_answer("eof1");
			if (que == '!') {
				int ans;
				cin >> ans;
				if (!cin) wrong_answer("eof2");
				if (ans != answer) wrong_answer("wrong answer: expected %d but found %d", answer, ans);
				hash *= 3;
				break;
			} else if (que == '?') {
				int L, R;
				cin >> L >> R;
				if (!cin) wrong_answer("eof3");
				if (L <= 0 || L > N) wrong_answer("left endpoint %d is out of range [1, %d]", L, N);
				if (R <= 0 || R > N) wrong_answer("right endpoint %d is out of range [1, %d]", R, N);
				if (L > R) wrong_answer("left endpoint (%d) is bigger than right endpoint (%d)", L, R);
				ll res = sumTo[R] - sumTo[L - 1];
				hash *= 1237618231;
				hash ^= L;
				hash *= 1237618231;
				hash ^= R;
				cout << res << endl;
				queries++;
			} else {
				wrong_answer("bad query type %d", (int)que);
			}
		}
	}

	int garbage;
	cin >> garbage;
	if (cin) wrong_answer("expected eof");

	judge_message("%d queries", queries);
	if (T == 1) {
		// sample (not used)
		accept_with_score(0);
	} else {
		double rat = (double)queries / (double)(T * N), score;
		const double maxRat = 0.55, minRat = 0.3;
		if (rat < minRat) score = 1;
		else if (rat > maxRat) score = 0;
		else score = (maxRat - rat) / (maxRat - minRat);
		accept_with_score(100.0 * score);
	}
}
