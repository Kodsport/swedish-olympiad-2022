#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int n,m;
vi A;
vi B;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d,e;

    cin >> n >> m;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }
    rep(c1,0,m){
        cin >> a;
        B.push_back(a);
    }
    sort(all(A));
    sort(all(B));
    if(n == m){
        ll ans = 0;
        rep(c1,0,n){
            ans += abs(A[c1]-B[c1]);
        }
        cout << ans << "\n";
    }
    else{
        vl pre, suf;
        ll cs1 = 0;
        ll cs2 = 0;
        for(int c1 = 0; c1 < n; c1++){
            pre.push_back(cs1);
            suf.push_back(cs2);
            if(c1 == m-1)break;
            cs1 += abs(A[c1]-B[c1]);
            cs2 += abs(A[n-c1-1]-B[m-c1-1]);
        }
        reverse(all(suf));
        ll ans = 1e18;
        rep(c1,0,m){
            ans = min(ans, pre[c1]+suf[c1]);
        }
        cout << ans << "\n";

    }

    return 0;
}
