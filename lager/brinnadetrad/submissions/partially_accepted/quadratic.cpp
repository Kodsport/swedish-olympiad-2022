#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MAXN = 500001;

int n;
ll X[MAXN] = {0};
ll A[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d,e;

    cin >> n;
    assert(n <= 4000);
    rep(c1,0,n){
        cin >> X[c1];
    }
    rep(c1,0,n){
        cin >> A[c1];
    }

    vl DP = {0};

    for(int c1 = 0; c1 < n; c1++){
        int i = c1;
        int hi = sz(DP)-1;
        for(int c2 = hi; c2 >= 0; c2--){
            if(DP[c2] <= X[i]){
                if(c2 == hi){
                    DP.push_back(DP[c2] + A[i]);
                }
                else{
                    DP[c2+1] = min(DP[c2+1], DP[c2] + A[i]);
                }
            }
        }
    }

    cout << sz(DP)-1 << "\n";

    return 0;
}
