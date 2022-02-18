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
  int n, q, x;
  cin >> n >> q;
  vector<vi> a_pos(n+10), q_pos(n+10);
  rep(i,0,n) {
    cin>>x;
    a_pos[min(x,n+5)].emplace_back(i);
  }
  rep(i,0,q) {
    cin>>x;
    q_pos[min(x,n+5)].emplace_back(i);
  }

  map<int,int> endpos; // relevant intervals, increasing
  multiset<int> lens; // {prev(it)->second - it->first + 1 : it \in endpos}

  auto fix = [&](auto it, int delta) { // maintain lens
    if(it == begin(endpos) || it == end(endpos)) return;
    int val = prev(it)->second - it->first + 1;
    if(delta == -1) lens.erase(lens.find(val));
    else if(delta == 1) lens.emplace(val);
    else assert(false);
  };

  auto remove = [&](auto it) { // remove endpos[a]
    fix(it,-1);
    fix(++it,-1);
    endpos.erase(prev(it));
    fix(it,+1);
  };

  auto add = [&](int a, int b) { // endpos[a] = b
    if(endpos.count(a)) remove(endpos.find(a));
    auto it = endpos.upper_bound(a);
    fix(it,-1);
    it = endpos.emplace(a,b).first;
    fix(it,+1);
    fix(next(it),+1);
    return it;
  };

  auto update = [&](int l, int v) { // endpos[i] = max(endpos[i], v) for all i >= l
    if(prev(endpos.upper_bound(l))->second >= v) return;
    auto it = add(l,v);
    while(next(it) != end(endpos) && next(it)->second <= v)
      remove(next(it));
  };

  add(0,0);
  add(n,1e9);

  vi ans(q,-1);
  rep(x,0,sz(a_pos)) {
    int l = 0;
    for(int i : a_pos[x]) {
      update(l,i+1);
      l = i+1;
    }
    update(l,1e9);

    for(int i : q_pos[x]) if(sz(lens)) ans[i] = *begin(lens);
  }

  rep(i,0,q) cout << ans[i] << "\n";
}
