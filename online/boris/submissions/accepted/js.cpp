#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef tuple<int, int, int, int> Boris;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
  
  int N;
  cin >> N;
  vector<Boris> B;
  rep(i,0,N) {
    int x, y, s, t;
    cin >> t >> s >> x >> y;
    B.emplace_back(t, x, y, s);
  }
  vector<int> dp(N);
  sort(all(B));

  rep(i,0,N) {
    dp[i] = get<3>(B[i]);
    rep(j,0,i) {
      int dx = get<1>(B[i]) - get<1>(B[j]);
      int dy = get<2>(B[i]) - get<2>(B[j]);
      int dt = get<0>(B[i]) - get<0>(B[j]);
      if (abs(dx) + abs(dy) <= dt) {
        dp[i] = max(dp[i], get<3>(B[i]) + dp[j]);
      }
    }
  }

  cout << *max_element(all(dp)) << endl;
}
