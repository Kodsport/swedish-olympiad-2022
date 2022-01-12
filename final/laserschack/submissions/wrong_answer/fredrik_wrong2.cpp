#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
    cin.sync_with_stdio(false);

    ll r,c;
    cin>>r>>c;
    vector<string> g(r);

    queue<tuple<ll,ll,ll>> q;
    ll ar,ac;
    rep(i,0,r) {
        cin>>g[i];
        rep(j,0,c){
            if(g[i][j]=='A'){
                ar = i;
                ac = j;
            }
            if(g[i][j]=='R'){
                q.emplace(i,j,0);
            }
        }
    }
    vector<vi> dist(r,vi(c,-1));
    while(sz(q)){
        ll x,y,d;
        tie(x,y,d) = q.front();
        q.pop();
        if(x<0 || x>=r || y<0 || y>=c || dist[x][y]!=-1)
            continue;
        dist[x][y] = d;
        q.emplace(x+1,y,d+1);
        q.emplace(x,y+1,d+1);
        q.emplace(x-1,y,d+1);
        q.emplace(x,y-1,d+1);
    }

    // rep(i,0,r){
    //     rep(j,0,c) cout<<dist[i][j];
    //     cout<<endl;
    // }

    queue<tuple<ll,ll,ll>> q2;
    q2.emplace(1e18,ar,ac);
    vector<vi> seen(r,vi(c));
    while(sz(q2)){
        ll x,y,mn;
        tie(mn,x,y) = q2.front();
        q2.pop();
        if(seen[x][y]) continue;
        seen[x][y] = 1;
        if(g[x][y]=='K') {
            cout<<mn<<endl;
            return 0;
        }

        trav(dir, vector<pii>({{0,1},{0,-1},{1,0},{-1,0}})){
            ll xi = x;
            ll yi = y;
            ll mni = mn;
            while(true) {
                xi += dir.first;
                yi += dir.second;
                if(xi<0 || xi>=r || yi<0 || yi>=c) break;
                mni = min(mni, dist[xi][yi]);
                if(g[xi][yi]=='o' || g[xi][yi]=='K'){
                    q2.emplace(mni,xi,yi);
                    break;
                }
            }
        }
    }
}

