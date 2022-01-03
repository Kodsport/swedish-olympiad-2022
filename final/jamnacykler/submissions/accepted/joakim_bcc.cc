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


vi num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
  int me = num[at] = ++Time, e, y, top = me;
  for (auto pa : ed[at]) if (pa.second != par) {
    tie(y, e) = pa;
    if (num[y]) {
      top = min(top, num[y]);
      if (num[y] < me)
        st.push_back(e);
    } else {
      int si = sz(st);
      int up = dfs(y, e, f);
      top = min(top, up);
      if (up == me) {
        st.push_back(e);
        f(vi(st.begin() + si, st.end()));
        st.resize(si);
      }
      else if (up < me) st.push_back(e);
      else { /* e is a bridge */ }
    }
  }
  return top;
}

template<class F>
void bicomps(F f) {
  num.assign(sz(ed), 0);
  rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  ++n;
  ed.resize(n);

  vector<pii> edges;
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    ed[x].emplace_back(y,i);
    ed[y].emplace_back(x,i);
    edges.emplace_back(x,y);
  }

  vector<vi> g(n);
  vi touch(n);

  auto f = [&](vi c){
    int siz = 0;
    for(int e : c) {
      auto [x,y] = edges[e];
      if(touch[x] == 0) touch[x] = 1, ++siz;
      if(touch[y] == 0) touch[y] = 1, ++siz;
    }
    for(int e : c) {
      auto [x,y] = edges[e];
      touch[x] = touch[y] = 0;
    }

    if(siz == sz(c)) { // found a cycle component
      if(sz(c)%2 == 0) {
        cout << "YES" << endl;
        cout << sz(c) << endl;
        rep(i,0,sz(c)) {
          if(edges[c[i]].first == edges[c[(i+1)%sz(c)]].first ||
             edges[c[i]].first == edges[c[(i+1)%sz(c)]].second)
            cout << edges[c[i]].first << " ";
          else
            cout << edges[c[i]].second << " ";
        }
        cout << endl;
        exit(0);
      }
      return;
    }

    assert(siz < sz(c));

    for(int e : c) {
      auto [x,y] = edges[e];
      g[x].emplace_back(y);
      g[y].emplace_back(x);
    }


    vi in_path(n,-1);
    vi pth;

    function<pii(int,int,bool)> nxt_large = [&](int x, int p, bool push_path) -> pii {
      if(push_path) {
        in_path[x] = sz(pth);
        pth.emplace_back(x);
      }
      if(sz(g[x]) >= 3) {
        return {x,1};
      }
      assert(sz(g[x]) == 2);
      auto res = nxt_large(g[x][0]^g[x][1]^p, x, push_path);
      return {res.first, res.second+1};
    };

    int x = -1;
    rep(i,0,n) if(sz(g[i]) >= 3) x = i;
    assert(x != -1);
    in_path[x] = 0;
    pth.emplace_back(x);

    while(true) {
      bool ok = false;
      assert(sz(g[x]) >= 3);
      for(int y : g[x]) {
        int yy = nxt_large(y,x, false).first;
        if(in_path[yy] == -1) {
          nxt_large(y,x, true);
          x = yy;
          ok = true;
        }
      }
      if(!ok) break;
    }

    assert(sz(g[x]) >= 3);
    vector<pii> ys;
    rep(t,0,3) ys.emplace_back(nxt_large(g[x][t],x,false));
    rep(at,0,3) rep(bt,at+1,3) {
      int a = ys[at].first;
      int b = ys[bt].first;
      int len = abs(a-b) + ys[at].second + ys[bt].second;
      assert(in_path[a] != -1 && in_path[b] != -1);

      if(len % 2 == 0) {
        if(in_path[a] > in_path[b]) swap(a,b), swap(at, bt);

        cout << "YES" << endl;
        cout << len << endl;
        rep(i, in_path[a], in_path[b]+1) {
          cout << pth[i] << " ";
        }
        pth.clear();
        nxt_large(g[x][bt],x,true);
        pth.pop_back();
        reverse(all(pth));
        for(int v : pth) cout << v << " ";
        cout << x << " ";

        pth.clear();
        nxt_large(g[x][at],x,true);
        pth.pop_back();
        for(int v : pth) cout << v << " ";

        cout << endl;

        exit(0);
      }
    }
    assert(false);
  };

  bicomps(f);

  cout << "NO" << endl;
}
