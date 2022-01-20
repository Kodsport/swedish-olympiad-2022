// @EXPECTED_GRADES@ AC AC AC TLE
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
  vector<tuple<int,int,int>> xfh;
  for(auto [n,delta] : vector<pii>{{a,1},{b,-1}}) {
    rep(i,0,n) {
      int x,ff,hh;
      cin>>x>>ff>>hh;
      xfh.emplace_back(x,delta*ff,hh);
    }
  }

  sort(all(xfh));
  vi nxt(up,1e9);
  rep(i,0,sz(xfh)) {
    auto [x,f,h] = xfh[i];
    nxt[x] = i;
  }
  for(int i = up-1; i--;) nxt[i] = min(nxt[i],nxt[i+1]);

  vector<pii> mast(m);
  for(auto& [x,h] : mast) cin >> x >> h;
  mast.emplace_back(-1e5,0);
  mast.emplace_back(up+1e5,0);
  sort(all(mast));

  auto cost = [&](int i, int j) -> ll {
    auto [x0,h0] = mast[i];
    auto [x1,h1] = mast[j];
    int dx = x1-x0;
    if(abs(h1-h0) > dx) return -1e18;

    ll res = 0;
    for(int i = nxt[max(x0,0)]; i < sz(xfh) && get<0>(xfh[i]) < x1; ++i) {
      auto [x,f,h] = xfh[i];
      assert(x >= x0 && x < x1);
      int height = 0;
      height = max(height, h0-(x-x0));
      height = max(height, h1-(x1-x));
      res += f*min(height,h);
    }

    return res;
  };

  vector<ll> dp(sz(mast),-1e18);
  dp[0] = 0;
  rep(j,1,sz(dp)) rep(i,0,j) dp[j] = max(dp[j],dp[i]+cost(i,j));

  cout << dp.back() << endl;
}
