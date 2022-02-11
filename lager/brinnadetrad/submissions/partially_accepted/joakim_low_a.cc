// @EXPECTED_GRADES@ AC AC WA WA AC
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
  vi a(n), x(n);
  rep(i,0,n) cin>>x[i];
  rep(i,0,n) cin>>a[i];
  vi ord(n);
  iota(all(ord),0);
  stable_sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });

  int ans = 0;
  ll sm = 0;
  int mx = -1;
  for(int i : ord) if(sm <= x[i] && (mx<i || sm+a[i]-a[mx] <= x[mx])) {
    mx = max(mx, i);
    ++ans;
    sm += a[i];
  }
  cout << ans << endl;
}
