// @EXPECTED_GRADES@ AC AC TLE TLE

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
  vi x(n),y(n),s(n),t(n);
  rep(i,0,n) cin>>t[i]>>s[i]>>x[i]>>y[i];
  ll ans = 0;
  function<void(int,ll)>go = [&](int i, ll cur) {
    cur += s[i];
    ans = max(ans, cur);
    rep(j,0,n) if(i != j && abs(x[i]-x[j]) + abs(y[i]-y[j]) + t[i] <= t[j])
      go(j,cur);
  };
  rep(i,0,n) go(i,0);
  cout << ans << endl;
}
