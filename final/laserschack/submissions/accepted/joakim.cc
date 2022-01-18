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
  int r, c;
  cin>>r>>c;
  vector<string> grid(r);
  rep(i,0,r) cin >> grid[i];

  vector<vi> dist(r,vi(c,1e9));
  {
    queue<pii> q;
    auto push = [&](int x, int y, int d) {
      if(dist[x][y] != 1e9) return;
      dist[x][y] = d;
      q.emplace(x,y);
    };
    rep(x,0,r) rep(y,0,c) if(grid[x][y] == 'R') push(x,y,0);


    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    auto valid = [&](int x, int y) { return 0 <= x && x < r && 0 <= y && y < c; };

    while(sz(q)) {
      auto [x,y] = q.front();
      q.pop();
      rep(d,0,4) {
        int nx = x + dx[d], ny = y + dy[d];
        if(!valid(nx,ny)) continue;
        push(nx,ny,dist[x][y]+1);
      }
    }
  }

  auto at = [&](int x, int y) { return x + r*y; };
  vector<vector<pii>> g(r*c);
  auto ae = [&](int a, int b, int d) {
    g[a].emplace_back(b,d);
    g[b].emplace_back(a,d);
  };

  int source = -1, sink = -1;
  rep(x,0,r) rep(y,0,c) {
    if(grid[x][y] == 'A') source = at(x,y);
    if(grid[x][y] == 'K') sink = at(x,y);
  }

  int lst = -1, mn = -1;
  auto proc = [&](int x, int y) {
      mn = min(mn,dist[x][y]);
      if(grid[x][y] == 'o' || grid[x][y] == 'A' || grid[x][y] == 'K') {
        if(lst != -1) ae(lst, at(x,y),mn);
        mn = dist[x][y];
        lst = at(x,y);
      }
  };
  rep(x,0,r) {
    lst = -1, mn = 1e9;
    rep(y,0,c) proc(x,y);
  }
  rep(y,0,c) {
    lst = -1, mn = 1e9;
    rep(x,0,r) proc(x,y);
  }

  vector<queue<int>> at_level(r*c+100);
  vi height(r*c,-1);
  auto push = [&](int x, int h) {
    if(h <= height[x]) return;
    height[x] = h;
    at_level[h].emplace(x);
  };
  push(source,sz(at_level)-1);

  for(int h = sz(at_level); h--;) {
    while(sz(at_level[h])) {
      int x = at_level[h].front();
      at_level[h].pop();
      if(height[x] != h) continue;
      for(auto [y,w] : g[x]) {
        push(y,min(w,h));
      }
    }
  }

  cout << height[sink] << endl;
}
