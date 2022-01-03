#include "testlib.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  string type = opt("type");
  int n = opt<int>("n");
  int max_s = opt<int>("max_s");
  int max_xy = opt<int>("max_xy");
  int max_t = opt<int>("max_t");

  vector<tuple<int,int,int,int>> v;
  set<tuple<int,int,int>> seen;
  auto try_add = [&](int t, int s, int x, int y) {
    if(seen.count({t,x,y})) return;
    seen.emplace(t,x,y);
    v.emplace_back(t,s,x,y);
  };
  auto add_rand = [&]() {
      int t = rnd.next(0,max_t);
      int s = rnd.next(1,max_s);
      int x = rnd.next(0,max_xy);
      int y = rnd.next(0,max_xy);
      try_add(t,s,x,y);
  };

  if(type == "random") {
    while(sz(v) < n) add_rand();
  }
  else if(type == "path") {
    int len = opt<int>("path_len");
    int x = rnd.next(0,max_xy), y = rnd.next(0,max_xy), t=0;
    int mv = max(max_t/(len+3),1);
    assert(len < max_t);
    rep(i,0,len) {
      int dx = rnd.next(0,mv);
      int dy = (dx == mv ? 0 : rnd.next(0,mv-dx));
      if(rnd.next(0,1)) swap(dx,dy);
      int lx = x, ly = y;
      x += rnd.any(vi{-1,1})*dx;
      y += rnd.any(vi{-1,1})*dy;
      x = max(0,min(x,max_xy));
      y = max(0,min(y,max_xy));
      t += abs(x-lx) + abs(y-ly) + (mv > 10 ? rnd.next(0,3) : 0);
      int s = rnd.next(max<int>(1,0.9*max_s), max_s);
      try_add(t,s,x,y);
    }
    if(max_s > 1) max_s /= 2;
    assert(t <= max_t);
    while(sz(v) < n) add_rand();
  }
  else assert(false);

  shuffle(all(v));

  assert(sz(v) == n);
  cout << n << endl;
  for(auto [t,s,x,y] : v)
    cout << t << " " << s << " " << x << " " << y << "\n";
}
