
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

  map<int,int> lens; // {prev(it)->second - it->first + 1 : it \in endpos}
  vi endpos(n);
  rep(i,0,n) {
    endpos[i] = i;
    lens[endpos[i]-i]++;
  }

  auto update = [&](int l, int v) { // endpos[i] = max(endpos[i], v) for all i >= l
    rep(i,l,n) {
      if(endpos[i] >= v) break;
      if(--lens[endpos[i]-i] == 0) lens.erase(endpos[i]-i);
      endpos[i] = v;
      if(endpos[i] != 1e9) lens[endpos[i]-i]++;
    }
  };

  vi ans(q,-1);
  rep(x,0,sz(a_pos)) {
    reverse(all(a_pos[x]));
    int val = 1e9;
    for(int i : a_pos[x]) {
      update(i+1,val);
      val = i+1;
    }
    update(0,val);

    for(int i : q_pos[x]) if(sz(lens)) ans[i] = begin(lens)->first;
  }

  rep(i,0,q) cout << ans[i] << "\n";
}
