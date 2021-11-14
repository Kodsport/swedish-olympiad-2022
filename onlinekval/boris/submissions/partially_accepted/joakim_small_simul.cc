// @EXPECTED_GRADES@ RTE RTE AC RTE

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

const int M=55;
int here[M][M][M];
int dp[M][M][M];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin>>n;
  rep(i,0,n) {
    int x, y, s, t;
    cin>>t>>s>>x>>y;
    x+=2;
    y+=2;
    t+=2;
    here[t][x][y] = s;
  }

  int dx[] = {-1,0,1,0,0};
  int dy[] = {0,1,0,-1,0};

  int ans = 0;
  rep(t,1,M) {
    rep(x,1,M-1) rep(y,1,M-1) {
      rep(d,0,5) {
        int nx = x + dx[d], ny = y + dy[d];
        dp[t][x][y] = max(dp[t][x][y], dp[t-1][nx][ny] + here[t][x][y]);
      }
      ans = max(ans, dp[t][x][y]);
    }
  }

  cout << ans << endl;
}
