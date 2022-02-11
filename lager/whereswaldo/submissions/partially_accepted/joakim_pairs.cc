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

void solve(int n) {

  map<pii,int> queries;
  auto query = [&](int l, int r) {
    if(queries.count({l,r})) return queries[{l,r}];
    int x;
    cout << "? " << l+1 << " " << r << endl;
    cin>>x;
    return queries[{l,r}] = x;
  };
#define answer(x) do { cout << "! " << (x)+1 << endl; return; } while(0)

  for(int i = 0; i < n; i += 2) {
    int x = query(i,i+2);
    if(x <= n+1) {
      int y = query(i,i+1);
      if(y == 1) answer(i);
      if(x-y == 1) answer(i+1);
    }
  }

  assert(false);
}

int main() {
  int t,n;
  cin>>t>>n;
  rep(i,0,n) solve(n);
}
