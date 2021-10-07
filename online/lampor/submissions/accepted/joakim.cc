#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef long double ld;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int r, c;
  cin>>r>>c;
  vi row(r), col(c);
  auto read = [&]() {
    char c;
    cin>>c;
    if(c == 'R') return 1;
    if(c == 'G') return 2;
    if(c == 'B') return 4;
    assert(false);
  };
  rep(_,0,2) {
    rep(i,0,c) col[i] |= read();
    rep(i,0,r) row[i] |= read();
  }

  vi row_cnt(8), col_cnt(8);
  for(auto x : col) ++col_cnt[x];
  for(auto x : row) ++row_cnt[x];

  ll ans = 0;
  rep(rmsk,0,8) rep(cmsk,0,8) if((rmsk|cmsk) == 7)
    ans += row_cnt[rmsk] * col_cnt[cmsk];

  cout << ans << endl;
}
