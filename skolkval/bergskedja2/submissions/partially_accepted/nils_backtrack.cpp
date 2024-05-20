//#pragma GCC optimize("O3")   //
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

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 9;

int grid[MAXN][MAXN] = {0};

int DX[4] = {0,0,-1,1};
int DY[4] = {1,-1,0,0};

bool inbounds(ll i, ll j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

bool taken[MAXN*MAXN] = {0};
int H[MAXN][MAXN] = {0};

int lower(ll i, ll j){
    ll res = 0;
    rep(c1,0,4){
        ll i2 = i + DX[c1];
        ll j2 = j + DY[c1];
        if(inbounds(i2,j2) && H[i2][j2] < H[i][j] && H[i2][j2] != 0)res++;
    }
    return res;
}

vi works;

bool brute(int i, int j){
    if(j == m)return brute(i+1,0);
    if(i == n){
        rep(c1,0,n){
            rep(c2,0,m){
                if(H[c1][c2] == 0 ||lower(c1, c2) != grid[c1][c2])return 0;
            }
        }
        return 1;
    }
    rep(h,1,n*m+1){
        if(!taken[h]){
            taken[h] = 1;
            H[i][j] = h;

            bool bad = 0;
            rep(c1,0,4){
                int i2 = i + DX[c1];
                int j2 = j + DY[c1];
                if(inbounds(i2,j2) && lower(i2,j2) > grid[i2][j2]){
                    bad = 1;
                    break;
                }
            }
            if(!bad){
                bad = !brute(i, j+1);
            }

            H[i][j] = 0;
            taken[h] = 0;
            if(!bad){
                if(i == 0 && j == 0){
                    works.push_back(h);
                }
                else{
                    return 1;
                }
            }
        }
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> m;
    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,m){
            grid[c1][c2] = s[c2]-'0';
        }
    }

    brute(0,0);
    cout << works[0] << " " << works.back() << "\n";

    return 0;
}
