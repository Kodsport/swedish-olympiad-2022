// @EXPECTED_GRADES@ WA AC AC WA WA
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
  int n;
  cin >> n;

  const int START = 0;
  const int END = 1;
  using T = tuple<int,int>; // (time,type)
  vector<T> events;

  rep(i,0,n) {
    int m;
    cin>>m;
    rep(j,0,m) {
      int l,r;
      cin>>l>>r;
      events.emplace_back(l,START);
      events.emplace_back(r,END);
    }
  }
  sort(all(events));

  int ans = 0;
  int active = 0;
  for(auto [x,t] : events) {
    if(t == START) ++active;
    else if(t == END) --active;
    else assert(false);
    ans = max(ans, active);
  }

  assert(active == 0);
  cout << ans << endl;
}
