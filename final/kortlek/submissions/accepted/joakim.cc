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
  vector<ll> a(n), b(n+1,1e18);
  rep(i,0,n) cin>>a[i];
  rep(i,0,m) cin>>b[i];
  sort(all(a));
  sort(all(b));

  ll cost = 0;
  rep(i,0,n) cost += abs(a[i]-b[i]);
  ll ans = cost;

  for(int i = n; i--;) {
    cost -= abs(a[i]-b[i]);
    cost += abs(a[i]-b[i+1]);
    ans = min(ans, cost);
  }

  cout << ans << endl;
}
