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
  vi x(n), a(n);
  rep(i,0,n) cin>>x[i];
  rep(i,0,n) cin>>a[i];

  ll sum = 0;
  priority_queue<int> pq;
  rep(i,0,n) {
    sum += a[i];
    pq.emplace(a[i]);
    if(sum > x[i]+a[i]) {
      sum -= pq.top();
      pq.pop();
    }
    assert(sum <= x[i]+a[i]);
  }
  cout << sz(pq) << endl;
}
