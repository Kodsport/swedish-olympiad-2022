// @EXPECTED_GRADES@ WA WA AC AC WA WA

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
  cin >> n >> m;
  vector<vi> g(n);
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  vi st;
  vi vis(n);
  vi parity(n,-1);
  int dd = 0;
  function<void(int,int)> dfs = [&](int x, int p) {
    if(vis[x]) {
      if(dd%2 != parity[x]) return;
      cout << "YES" << endl;
      vi c = {x};
      while(st.back() != x) {
        c.push_back(st.back());
        st.pop_back();
      }
      cout << sz(c) << endl;
      rep(i,0,sz(c)) cout << c[i]+1 << " ";
      cout << endl;
      exit(0);
    }
    st.emplace_back(x);
    vis[x] = true;
    parity[x] = dd;
    dd = 1-dd;
    for(int y : g[x]) if(y != p) dfs(y,x);
    st.pop_back();
    dd = 1-dd;
  };
  rep(i,0,n) if(!vis[i]) dfs(i,-1);

  cout << "NO" << endl;
}
