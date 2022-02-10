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

vi X,A,ind;

bool comp(int i, int j){
    return A[i] < A[j];
}

int main() {
    int n;
    cin >> n;
    rep(c1,0,n){
        int a;
        cin >> a;
        X.push_back(a);
    }
    rep(c1,0,n){
        int a;
        cin >> a;
        A.push_back(a);
        ind.push_back(c1);
    }
    sort(all(ind), comp);

    ll sum = 0;
    int ans = 0;
    rep(c1,0,n){
        int i = ind[c1];
        if(sum <= X[i]){
            sum += A[i];
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}
