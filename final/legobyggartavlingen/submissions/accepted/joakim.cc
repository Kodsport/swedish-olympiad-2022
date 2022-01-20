#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int a,b,m;
  cin>>a>>b>>m;
  const int up = 1e6+10;
  vi f(up), h(up);
  for(auto [n,delta] : vector<pii>{{a,1},{b,-1}}) {
    rep(i,0,n) {
      int x,ff,hh;
      cin>>x>>ff>>hh;
      assert(f[x]==0);
      f[x] = delta*ff;
      h[x] = hh;
    }
  }

  vector<pii> mast(m);
  for(auto& [x,h] : mast) cin >> x >> h;
  mast.emplace_back(-1e5,1);
  mast.emplace_back(up+1e5,1);
  sort(all(mast));

  vector<vector<ll>> costR(sz(mast)), costL(sz(mast));
  rep(k,0,sz(mast)) {
    auto [x0,h0] = mast[k];
    costR[k].resize(h0,0);
    costL[k].resize(h0,0);
    rep(i,0,h0) {
      int x = x0+i;
      int height = h0-i;
      if(i) costR[k][i] += costR[k][i-1];
      if(0 <= x && x < up) costR[k][i] += f[x]*min(height,h[x]);
    }
    rep(i,0,h0) {
      int x = x0-i;
      int height = h0-i;
      if(i) costL[k][i] += costL[k][i-1];
      if(i && 0 <= x && x < up) costL[k][i] += f[x]*min(height,h[x]);
    }
  }

  auto cost = [&](int i, int j) -> ll {
    assert(i < j);
    auto [x0,h0] = mast[i];
    auto [x1,h1] = mast[j];
    int dx = x1-x0;
    int dh = h1-h0;
    if(abs(dh) >= dx) return -1e18;

    int r1 = (dx-dh)/2;
    int r2 = x1-x0-r1-1;
    assert(r1 >= 0 && r1 <= x1-x0);
    assert(r2 >= 0 && r2 <= x1-x0);
    ll res = costR[i][min(r1,h0-1)] + costL[j][min(r2,h1-1)];
    return res;
  };

  vector<ll> dp(sz(mast),-1e18);
  dp[0] = 0;
  rep(j,1,sz(dp)) rep(i,0,j) dp[j] = max(dp[j],dp[i]+cost(i,j));

  cout << dp.back() << endl;
}
