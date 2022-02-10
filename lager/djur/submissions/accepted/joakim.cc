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


struct Dinic {
  struct Edge {
    int to, rev;
    ll c, oc;
    ll flow() { return max(oc - c, 0LL); } // if you need flows
  };
  vi lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, ll c, ll rcap = 0) {
    adj[a].push_back({b, sz(adj[b]), c, c});
    adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
  }

  ll dfs(int v, int t, ll f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < sz(adj[v]); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1)
        if (ll p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }

  ll calc(int s, int t) {
    ll flow = 0; q[0] = s;
    rep(L,30,31) do { // 'int L=30' maybe faster for random data
      lvl = ptr = vi(sz(q));
      int qi = 0, qe = lvl[s] = 1;
      while (qi < qe && !lvl[t]) {
        int v = q[qi++];
        for (Edge e : adj[v])
          if (!lvl[e.to] && e.c >> (30 - L))
            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
      }
      while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
    } while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int r, c;
  cin>>r>>c;
  vector<string> grid(r);
  rep(i,0,r) cin>>grid[i];
  assert(grid[0][0] == '.' && grid[r-1][c-1] == '.');

  auto IN = [&](int i, int j) { return i+r*j; };
  auto OUT = [&](int i, int j) { return r*c + IN(i,j); };
  Dinic mf(2*r*c);
  rep(i,0,r) rep(j,0,c) mf.addEdge(IN(i,j), OUT(i,j), 1);
  auto ae = [&](int x1, int y1, int x2, int y2) {
    mf.addEdge(OUT(x1,y1), IN(x2,y2), 1);
    mf.addEdge(OUT(x2,y2), IN(x1,y1), 1);
  };
  rep(i,0,r) rep(j,0,c) {
    if(i && grid[i-1][j] == '.' && grid[i][j] == '.')
      ae(i-1,j,i,j);
    if(j && grid[i][j-1] == '.' && grid[i][j] == '.')
      ae(i,j-1,i,j);
  }

  int source = OUT(0,0), sink = IN(r-1,c-1);
  int rk = mf.calc(source, sink);
  debug(rk);
  assert(rk <= 2);
  if(rk != 2) {
    cout << "NO" << endl;
    return 0;
  }

  for(char ch : string("VK")) {
    int x = 0, y = 0;
    while(x != r-1 || y != c-1) {
      debug(x,y);
      assert(grid[x][y] == '.');
      if(x+y) grid[x][y] = ch;
      bool ok = false;
      for(auto& e : mf.adj[OUT(x,y)]) if(e.flow()) {
        e.oc = 0;
        x = e.to%r;
        y = e.to/r;
        ok = true;
        break;
      }
      assert(ok);
    }
  }

  cout << "YES" << endl;
  rep(i,0,r) cout << grid[i] << "\n";
}
