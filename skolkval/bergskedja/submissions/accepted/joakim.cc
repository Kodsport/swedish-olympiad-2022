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
  int n, m;
  cin>>n>>m;
  vector<string> h(n);
  rep(i,0,n) cin>>h[i];

  int dx[] = {-1,0,1,0};
  int dy[] = {0,1,0,-1};
  auto valid = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };

  vector<vi> g(n*m), gr(n*m);
  auto at = [&](int x, int y) { return x + n*y; };
  auto ae = [&](int a, int b) {
    g[a].emplace_back(b);
    gr[b].emplace_back(a);
  };

  queue<pii> q;
  rep(x,0,n) rep(y,0,m) if(h[x][y] == '0') q.emplace(x,y);
  while(sz(q)) {
    auto [x,y] = q.front();
    q.pop();
    rep(d,0,4) {
      int nx = x + dx[d], ny = y + dy[d];
      if(!valid(nx,ny)) continue;
      if(--h[nx][ny] == '0') q.emplace(nx,ny);
      if(h[nx][ny] >= '0') ae(at(nx,ny),at(x,y));
    }
  }

  auto dfs = [&](auto& rec, int x, auto& g, auto& vis) {
    if(vis[x]++) return;
    for(int y : g[x]) rec(rec,y,g,vis);
  };
  vi vis_f(n*m), vis_r(n*m);
  dfs(dfs,at(0,0),g,vis_f);
  dfs(dfs,at(0,0),gr,vis_r);

  int low = n*m - count(all(vis_f),0);
  int hi = 1 + count(all(vis_r),0);
  cout << low << " " << hi << endl;
}
