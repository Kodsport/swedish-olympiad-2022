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

int r, c;
vector<string> grid;

const int max_rc = 40123;

bitset<max_rc> blocked;
bitset<max_rc> maskL, maskR;

void smoke_step(){
  blocked = blocked
    | ((blocked&maskL)>>1)
    | ((blocked&maskR)<<1)
    | (blocked>>c)
    | (blocked<<c);
}

int TIM = 99;
int vis[max_rc];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int ax = -1, ay = -1;
int kx = -1, ky = -1;

bool dfs(int x, int y) {
  if(blocked[x*c+y]) return false;
  if(vis[x*c+y] == TIM) return false;
  vis[x*c+y] = TIM;
  if(grid[x][y] == 'K') return true;
  rep(d,0,4) {
    int rx = x < kx ? dx[d] : -dx[d];
    int ry = y < ky ? dy[d] : -dy[d];
    int nx = x+rx, ny = y+ry;
    while(nx >= 0 && ny >= 0 && nx < r && ny < c && !blocked[nx*c+ny]) {
      if(grid[nx][ny] != '.'){
        if(dfs(nx,ny)) return true;
        break;
      }
      nx += rx;
      ny += ry;
    }
  }
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin>>r>>c;
  grid.resize(r);
  rep(i,0,r) cin >> grid[i];

  rep(i,0,r) rep(j,0,c) blocked[i*c+j] = (grid[i][j]=='R');
  rep(i,0,r) rep(j,0,c) {
    maskL[i*c+j] = (j ? 1 : 0);
    maskR[i*c+j] = (j+1<c ? 1 : 0);
  }

  rep(i,0,r) rep(j,0,c) if(grid[i][j] == 'A') ax = i, ay = j;
  rep(i,0,r) rep(j,0,c) if(grid[i][j] == 'K') kx = i, ky = j;

  rep(k,1,r*c+100) {
    smoke_step();
    ++TIM;
    if(!dfs(ax,ay)) {
      cout << k << endl;
      exit(0);
    }
  }
  assert(false);
}
