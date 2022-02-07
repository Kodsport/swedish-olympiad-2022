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

const int MAXN = 400001;

vl A,D,ind;

bool comp(int i,int j){
    return A[i] < A[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;
    cin >> n;

    rep(c1,0,n){
        cin >> a;
        D.push_back(a);
        ind.push_back(c1);
    }
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }

    int ans = 0;
    ll sum = 0;
    sort(all(ind), comp);
    rep(c1,0,n){
        int i = ind[c1];
        if(sum+A[i] <= D[i]){
            ans++;
            sum += A[i];
        }
    }
    cout << ans << "\n";

    return 0;
}
