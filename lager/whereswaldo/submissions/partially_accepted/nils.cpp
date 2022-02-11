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

bool DEBUG = 0;

vi P;
int moves = 0;


int ask(int L, int R){
    moves++;
    if(!DEBUG){
        cout <<"? " << L+1 << " " << R+1 << "\n";
        fflush(stdout);
        int sum;
        cin >> sum;
        return sum;
    }
    else{
        int sum = 0;
        rep(c1,L,R+1){
            sum += P[c1];
        }
        return sum;
    }
    return -1;
}

vi ind;
vi SUM;

bool comp(int i, int j){
    return SUM[i] < SUM[j];
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    const int BLOCK = 7;
    cin >> T;
    cin >> n;
    rep(c4,0,T){
        ind.clear();
        SUM.clear();
        if(DEBUG){
            P.clear();
            rep(c1,0,n){
                P.push_back(c1+1);
            }
            random_shuffle(all(P));
        }
        vector<pii> intervals;
        for(int i = 0; i < n; i+=BLOCK){
            int j = i+BLOCK-1;
            j = min(j, int(n-1));
            ind.push_back(sz(ind));
            intervals.push_back({i, j});
            SUM.push_back(ask(i,j));
        }
        sort(all(ind), comp);
        int ans = -1;
        rep(c1,0,sz(ind)){
            int i = ind[c1];
            int sum = 0;
            rep(c2,intervals[i].first,intervals[i].second){
                int temp = ask(c2,c2);
                if(temp == 1){
                    ans = c2;
                    break;
                }
                sum += temp;
            }
            if(ans != -1)break;
            if(SUM[i]-sum == 1){
                ans = intervals[i].second;
                break;
            }
        }
        if(!DEBUG)cout << "! " << ans+1 << "\n";
        fflush(stdout);
    }
    return 0;
}
