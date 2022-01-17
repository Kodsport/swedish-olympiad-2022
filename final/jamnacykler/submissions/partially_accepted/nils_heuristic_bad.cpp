#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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

ll n,m,k,q,T;

const int MAXN = 100001;

// Idea: randomly shuffle adjacency list, do a DFS and look for a back edge that connects
// vertices of different parities.

vector<vi> C(MAXN, vi());

int dist[MAXN] = {0};
bool mark[MAXN] = {0};
int parent[MAXN] = {0};
int start, stop;

void dfs(int i, int par){
    mark[i] = 1;
    parent[i] = par;
    dist[i] = 0;
    if(par != -1)dist[i] = dist[par]+1;
    trav(y, C[i]){
        if(mark[y] == 0){
            dfs(y, i);
        }
        else{
            if(dist[y]%2 != dist[i]%2 && dist[i]-dist[y] > 1){
                start = i;
                stop = y;
            }
        }
    }
}

vi play(){
    rep(c1,0,n){
        mark[c1] = 0;
        dist[c1] = 0;
        random_shuffle(all(C[c1]));
    }
    start = -1;
    stop = -1;

    rep(c1,0,n){
        if(!mark[c1])dfs(c1,-1);
    }

    vi res = {};
    if(start != -1){
        res.push_back(start);
        while(start != stop){
            start = parent[start];
            res.push_back(start);

        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c,d,e;

    cin >> n >> m;
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    int lim = 1;
    rep(_,0,lim){
        vi res = play();
        if(sz(res) > 0){
            cout << "YES\n";
            cout << sz(res) << "\n";
            trav(y, res){
                cout << y+1 << " ";
            }cout << "\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}
