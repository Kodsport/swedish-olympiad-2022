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

bool mark[MAXN] = {0};
vector<string> grid;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c,d,e;
    cin >> n >> m;

    if(n == 1 || m == 1){
        cout << "NO\n";
        return 0;
    }

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

    cout << "YES\n";
    rep(c1,0,n){
        cout << '.' << "\n";
    }

    return 0;
}
