// @EXPECTED_GRADES@ AC WA WA WA

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
  int t,s,x,y;
  cin>>t>>s>>x>>y;
  int t1,s1 = 0,x1,y1;
  if(n == 2) cin>>t1>>s1>>x1>>y1;
  if(abs(t1-t) >= abs(x1-x) + abs(y1-y)) cout << s1 + s << endl;
  else cout << max(s1, s) << endl;
}
