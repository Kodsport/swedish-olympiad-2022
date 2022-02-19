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

bool A[26][26] = {0};

string s;
vi VS;
int parent[MAXN] = {0};
int nex[MAXN] = {0};

vector<string> ANS;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> k >> n;
    rep(c1,0,k){
        string t;
        cin >> t;
        rep(c2,0,k){
            A[c1][c2] = (t[c2] == '1');
        }
    }
    cin >> s;
    rep(c1,0,n){
        VS.push_back(s[c1]-'a');
    }

    string ans = "";

    vi V;
    rep(c1,0,n){
        while(sz(V) > 0 && !A[VS[V.back()]][VS[c1]]){
            V.pop_back();
        }
        if(sz(V) == 0){
            parent[c1] = -1;
        }
        else{
            parent[c1] = V.back();
        }
        V.push_back(c1);
    }

    rep(c1,0,n){
        nex[c1] = n;
        rep(c2,c1+1,n){
            if(parent[c2] < c1){
                nex[c1] = c2;
                break;
            }
        }
        ANS.push_back("");
    }

    for(int c1 = n-1; c1 >= 0; c1--){
        if(nex[c1] == n){
            ANS[c1] = s[c1];
        }
        else{
            vector<string> candidates;
            rep(c2,c1+1,nex[c1]+1){
                candidates.push_back(ANS[c2]);
            }
            sort(all(candidates));
            ANS[c1] = s[c1] + candidates[0];
        }
    }
    cout << ANS[0] << "\n";


    return 0;
}
