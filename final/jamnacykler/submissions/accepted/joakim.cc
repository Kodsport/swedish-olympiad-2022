#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
#define debug(x) cerr << "[" <<#x << " = " << x << "]" << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

struct edge {
  int x,y;
  int id;
  int l = -1, r = -1;
  int len = 1;
  int other(int a) { return x^y^a; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  ++n;
  vector<edge> edges;
  vector<set<int>> g(n);
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    edge e{x,y,i};
    edges.emplace_back(e);
    g[x].emplace(e.id);
    g[y].emplace(e.id);
  }
  //debug("in");

  bool printed_first = true;
  function<void(int,edge)> print_edge = [&](int x, edge e) {
    assert(x == e.x || x == e.y);
    if(e.l == -1) {
      if(printed_first) cout << " ";
      printed_first = true;
      cout << x;
      return;
    }
    if(x != e.x) swap(e.l, e.r);
    print_edge(x, edges[e.l]);
    print_edge(edges[e.l].other(x), edges[e.r]);
  };
  auto answer = [&](edge e) {
    assert(e.x == e.y);
    assert(e.len % 2 == 0);
    cout << "YES" << endl;
    cout << e.len << endl;
    printed_first = false;
    print_edge(e.x, e);
    cout << endl;
    exit(0);
  };

  auto merge_edge = [&](edge e, edge f) {
    int mid = -1;
    if(e.x == f.x || e.x == f.y) mid = e.x;
    else mid = e.y;
    assert(mid == e.x || mid == e.y);
    assert(mid == f.x || mid == f.y);
    edge res;
    res.x = e.other(mid);
    res.y = f.other(mid);
    res.l = e.id;
    res.r = f.id;
    res.len = e.len + f.len;
    res.id = sz(edges);
    edges.emplace_back(res);
    //debug("merge");
    //print_edge(e.x,e); cout << " " << e.y << " len=" << e.len << endl;
    //print_edge(f.x,f); cout << " " << f.y << " len=" << f.len << endl;
    //debug("=");
    //print_edge(res.x,res); cout << " " << res.y << " len=" << res.len << endl;
    return res;
  };


  vi dead(n,false);
  queue<int> q;
  rep(x,0,n) if(sz(g[x]) <= 2) q.emplace(x);

  while(!q.empty()) {
    int x = q.front();
    q.pop();
    if(dead[x]) continue;
    dead[x] = true;

    vi eids;
    for(int eid : g[x]) {
      eids.emplace_back(eid);

      int y = edges[eid].other(x);
      g[y].erase(eid);
    }

    assert(sz(eids) <= 2);
    if(sz(eids) == 2) {
      int a = eids[0];
      int b = eids[1];
      edge e = merge_edge(edges[a], edges[b]);
      if(e.x == e.y) {
        if(e.len % 2 == 0) answer(e);
      }
      else {
        g[e.x].emplace(e.id);
        g[e.y].emplace(e.id);
      }
    }

    for(int eid : g[x]) {
      int y = edges[eid].other(x);
      if(sz(g[y]) <= 2) q.emplace(y);
    }
  }

  //debug("q");

  vi in_path(n, -1);
  vi p(n);
  rep(i,0,n) if(!dead[i]) {
    //debug("remain");
    int x = i;
    while(true) {
      in_path[x] = sz(p);
      bool ok = false;
      for(int eid : g[x]) {
        int y = edges[eid].other(x);
        if(in_path[y] == -1) {
          p.emplace_back(eid);
          g[y].erase(eid);
          x = y;
          ok = true;
          break;
        }
      }
      if(!ok) break;
    }
    //debug("path found");

    assert(sz(g[x]) >= 2);

    int a = *begin(g[x]);
    int b = *next(begin(g[x]));
    int ax = edges[a].other(x);
    int bx = edges[b].other(x);
    assert(in_path[ax] != -1 && in_path[bx] != -1);
    if(in_path[ax] > in_path[bx]) swap(ax,bx);

    for(int q : {a,b}) {
      edge e = edges[q];
      rep(i,in_path[ax],sz(p)) e = merge_edge(e, edges[p[i]]);
      if(e.len % 2 == 0) answer(e);
    }

    edge e = merge_edge(edges[a], edges[b]);
    rep(i,in_path[ax],in_path[bx]) e = merge_edge(e, edges[p[i]]);
    if(e.len % 2 == 0) answer(e);

    assert(false);
  }

  cout << "NO" << endl;
}
