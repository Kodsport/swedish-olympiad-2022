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
    rep(c1,0,n){
        cin >> a;
        X[c1] = a;
    }
    rep(c1,0,n){
        cin >> a;
        A[c1] = a;
    }

    set<pair<ll,ll> > S;
    S.insert({0,0});
    ll sum = 0;
    rep(c1,0,n){
        int i = c1;
        S.insert({A[i], i});
        sum += A[i];
        auto last = S.end();
        last--;
        if(sum-A[i] > X[i]){
            sum -= (*last).first;
            S.erase(last);
        }
    }
    cout << sz(S)-1 << "\n";

    return 0;
}
