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

const int MAXN = 200001;

int F[MAXN] = {0};

vi A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> q;
    assert(q == 1);

    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }

    cin >> k;

    if(k >= n){
        cout << "-1\n";
        return 0;
    }

    int zeros = k+1;
    int ans = big;

    int L = 0;
    rep(c1,0,n){
        if(A[c1] <= k){
            if(F[A[c1]] == 0)zeros--;
            F[A[c1]]++;
        }
        if(zeros == 0){
            while(1){
                if(A[L] <= k && F[A[L]] == 1)break;
                if(A[L] <= k)F[A[L]]--;
                L++;
            }
            ans = min(ans, c1-L+1);
        }
    }
    if(ans == big)ans=-1;
    cout << ans << "\n";

    return 0;
}
