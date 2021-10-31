// @EXPECTED_GRADES@ AC AC RTE AC RTE
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
  cin>>n;
  const int K = 4444;
  using bs = bitset<K>;
  vector<bs> ok(n);
  rep(i,0,n) {
    int m;
    cin>>m;
    assert(m);
    rep(j,0,m){
      int l, r;
      cin>>l>>r;
      assert(r < K);
      rep(x,l,r+1) ok[i][x] = 1;
    }
  }
  int ans = 0;
  rep(x,0,K) {
    int cnt = 0;
    rep(i,0,n) if(ok[i][x]) ++cnt;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
