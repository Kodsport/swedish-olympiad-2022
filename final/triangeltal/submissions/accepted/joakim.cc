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

void bad(string s = "NO") {
  cout << s << endl;
  exit(0);
}
void answer(string ans) {
  cout << "YES" << endl;
  cout << ans << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  vi ord(n);
  iota(all(ord),0);
  sort(all(ord),[&](int i, int j){return a[i]<a[j];});
  sort(all(a));

  int mx1 = a.back();
  if(mx1 >= n) bad();

  [&](){ // 231
    int mx2 = a[mx1-1];
    if(mx1+mx2 >= n) return;
    int mx3 = a[mx1+mx2-1];
    if(mx1+mx2+mx3 > n) return;
    string ans(n,'?');
    rep(i,0,n) ans[ord[i]] = i<mx1 ? '2' : i<mx1+mx2 ? '3' : '1';
    answer(ans);
  }();

  rep(mx3,1,n) { // 321
    int mx2 = n-mx3-mx1;
    if(mx2 <= 0) continue;
    if(a[mx2-1] > mx3) continue;
    if(a[mx1+mx2-1] > mx2) continue;
    string ans(n,'?');
    rep(i,0,n) ans[ord[i]] = i<mx2 ? '3' : i<mx1+mx2 ? '2' : '1';
    answer(ans);
  }

  bad();
}
