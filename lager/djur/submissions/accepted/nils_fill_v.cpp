#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

ll n,m;

const int MAXN = 200001;

vector<vector<bool> > blocked;

int DX[4] = {0, 1, 0, -1};
int DY[4] = {1, 0, -1, 0};

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int hsh(int i, int j){
    return i*m+j;
}

bool mark[MAXN] = {0};

vector<string> grid;

vector<pii> solve1(bool turn_right=1){
    vi dirs = {(!turn_right)};
    vector<pii> res = {{0,0}};
    mark[0] = 1;
    while(sz(res) > 0){
        int i = res.back().first;
        int j = res.back().second;
        int dir = dirs.back();
        bool yes = 0;
        rep(c4,0,4){
            int d = (dir+3+c4)%4;
            if(!turn_right)d = (dir+5-c4)%4;
            int i2 = i+DX[d];
            int j2 = j+DY[d];
            if(i2 == n-1 && j2 == m-1)return res;
            if(inbounds(i2,j2) && mark[hsh(i2,j2)] == 0 && !blocked[i2][j2]){
                mark[hsh(i2,j2)] = 1;
                res.push_back({i2,j2});
                dirs.push_back(d);
                yes = 1;
                break;
            }
        }
        if(!yes){
            res.pop_back();
            dirs.pop_back();
        }
    }
    return {};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c,d,e;
    cin >> n >> m;
    rep(c1,0,n){
        vector<bool> temp;
        string s;
        cin >> s;
        grid.push_back(s);
        rep(c2,0,m){
            temp.push_back((s[c2] == '#'));
        }
        blocked.push_back(temp);
    }

    vector<pii> rabbit = solve1();

    if(sz(rabbit) == 0){
        cout << "NO\n";
        return 0;
    }

    trav(p, rabbit){
        grid[p.first][p.second] = 'K';
    }

    mark[0] = 0;
    vector<pii> wolf = solve1(0);

    if(sz(wolf) == 0){
        cout << "NO\n";
        return 0;
    }
    trav(p, wolf){
        grid[p.first][p.second] = 'V';
    }
    grid[0][0] = '.';

    queue<pii> Q;
    Q.push({0,0});
    vector<vector<bool>> marked(n, vector<bool>(m, 0));

    while(!Q.empty()){
        int i = Q.front().first;
        int j = Q.front().second;
        grid[i][j] = 'V';
        Q.pop();
        if(!marked[i][j]){
            marked[i][j] = 1;
            rep(c1,0,4){
                int i2 = i + DX[c1];
                int j2 = j + DY[c1];
                if(inbounds(i2,j2) && !marked[i2][j2] && (grid[i2][j2] == '.' || grid[i2][j2] == 'V')){
                    Q.push({i2,j2});
                }
            }
        }
    }
    grid[0][0] = '.';
    grid[n-1][m-1] = '.';

    cout << "YES\n";
    rep(c1,0,n){
        cout << grid[c1] << "\n";
    }

    return 0;
}
