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

  priority_queue<tuple<ld,int,int,int>> pq; // [average, l, r, sum]
  auto push = [&](int l, int r, int sum) {
    assert(sum != 1);
    if(l+1 == r) return;
    pq.emplace(-sum/ld(r-l),l,r,sum);
  };

  push(0,n,n*(n+1)/2);
  while(sz(pq)) {
    auto [_,l,r,sum] = pq.top();
    pq.pop();
    int mid = (l+r+1)/2;
    int lsum = query(l,mid);
    int rsum = sum-lsum;
    if(lsum == 1) answer(l);
    if(rsum == 1) answer(mid);
    push(l,mid,lsum);
    push(mid,r,rsum);
  }

  assert(false);
}

int main() {
  int t,n;
  cin>>t>>n;
  rep(i,0,n) solve(n);
}
