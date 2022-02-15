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

ll n,k;
const int MAXN = 200001;

vector<vi> C(MAXN, vi());
vector<vl> CW(MAXN, vl());

ll DPE[MAXN][2] = {0};
ll DPW[MAXN][2] = {0};
bool DPC[MAXN][2] = {0};

pll dp(int i, bool mode){
    if(DPC[i][mode])return {DPE[i][mode], DPW[i][mode]};
    vector<pll> upgrades;
    pll ans = {0,0};
    rep(c1,0,sz(C[i])){
        int j = C[i][c1];
        ll w = CW[i][c1];
        pll base = dp(j, 0);
        ans.first += base.first;
        ans.second += base.second;
        pll better = dp(j, 1);
        better.first++;
        better.second += w;
        upgrades.push_back({better.first-base.first, better.second-base.second});
    }
    sort(all(upgrades));
    reverse(all(upgrades));
    rep(c1,0,k-int(mode)){
        if(c1 >= sz(upgrades))break;
        pll now = upgrades[c1];
        if(now.first > 0 || (now.first == 0 && now.second > 0)){
            ans.first += now.first;
            ans.second += now.second;
        }
    }
    DPE[i][mode] = ans.first;
    DPW[i][mode] = ans.second;
    DPC[i][mode] = 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d,e;

    cin >> n >> k;
    rep(c1,1,n){
        cin >> a >> b;
        a--;
        C[a].push_back(c1);
        CW[a].push_back(-b);
    }
    for(int c1 = n-1; c1 >= 0; c1--){
        dp(c1,0);
        dp(c1,1);
    }
    pll ans = dp(0,0);
    cout << ans.first << " " << -ans.second << "\n";

    return 0;
}
