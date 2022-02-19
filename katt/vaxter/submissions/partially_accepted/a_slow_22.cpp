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

const int MAXN = 200002;
const int big = 1000000007;

int n,q;
vi A;

int ANS[MAXN] = {0};
int latest[MAXN] = {0};

int main() {

    cin >> n >> q;
    assert(n <= 2000);
    rep(c1,0,n){
        int a;
        cin >> a;
        A.push_back(a);
        latest[c1] = -1;
        ANS[c1] = big;
    }
    rep(c1,0,n){
        latest[A[c1]] = c1;
        int mi = big;
        rep(c2,0,n){
            mi = min(mi, latest[c2]);
            if(mi == -1)break;
            ANS[c2] = min(ANS[c2], c1-mi+1);
        }
    }
    vi Q;
    rep(c1,0,q){
        int a;
        cin >> a;
        Q.push_back(a);
    }
    rep(c1,0,q){
        int a = Q[c1];
        if(a >= n || ANS[a] == big){
            cout << "-1\n";
        }
        else{
            cout << ANS[a] << "\n";
        }
    }

    return 0;
}
