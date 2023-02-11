// @EXPECTED_GRADES@ AC TLE TLE TLE TLE TLE

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
  int n,m;
  cin >> n >> m;
  set<pii> ed;
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    ed.emplace(x,y);
    ed.emplace(y,x);
  }
  vi ord(n);
  iota(all(ord),1);
  do {
    rep(k,0,n) {
      if(k && !ed.count(pii(ord[k-1],ord[k]))) break;
      if(k >= 3 && k % 2 == 1 && ed.count(pii(ord[k],ord[0]))) {
        cout << "YES" << endl;
        cout << k+1 << endl;
        rep(i,0,k+1) cout << ord[i] << " ";
        cout << endl;
        exit(0);
      }
    }
  } while(next_permutation(all(ord)));

  cout << "NO" << endl;
}
