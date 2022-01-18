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
  int n,b;
  cin>>n>>b;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  int r = 0, ans = 0;
  rep(i,0,n) {
    while(r < n && a[r] <= b) b -= a[r], ++r;
    ans = max(ans,r-i);
    b += a[i];
  }
  cout << ans << endl;
}
