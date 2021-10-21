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
  vector<tuple<int,int,int,int>> v(n);
  for(auto& [t,s,x,y] : v) cin>>t>>s>>x>>y;
  sort(all(v));

  vi dp(n);
  rep(i,0,n) {
    auto [t,s,x,y] = v[i];
    rep(j,0,i) {
      auto [tj,_,xj,yj] = v[j];
      if(tj + abs(x-xj) + abs(y-yj) <= t)
        dp[i] = max(dp[i], dp[j]);
    }
    dp[i] += s;
  }

  cout << *max_element(all(dp)) << endl;
}
