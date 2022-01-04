#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(ll i = a; i<ll(b);i++)
#define trav(x,s) for(auto &x: s)
#define all(v) v.begin(),v.end()
#define sz(v) ll(v.size())

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll n;
vector<vi> e;
vector<bool> seen;

vi depth;
vi visitStack;
vector<pii> cyclesInStack;

void printAns(vi cyc){
    cout<<"YES"<<endl;
    cout<<sz(cyc)<<endl;
    trav(x,cyc) cout<<x+1<<" ";
    cout<<endl;
    exit(0);
}

void dfs(ll v,ll d){
    seen[v] = true;
    depth[v] = d;
    visitStack.push_back(v);
    
    trav(u,e[v]){
        if(seen[u] && depth[v]-depth[u]!=1){
            if((depth[v]-depth[u]+1)%2==0){
                vi cyc;
                rep(i,depth[u],depth[v]+1)
                    cyc.push_back(visitStack[i]);
                printAns(cyc);
            }
            if(sz(cyclesInStack)&&cyclesInStack.back().first>depth[u]){
                auto [da,db] = cyclesInStack.back();
                ll du = depth[u];
                ll dv = depth[v];
                vi cyc;
                for(ll i = du; i!=db; i += (db-du)/abs(db-du))
                    cyc.push_back(visitStack[i]);
                if(db!=da) cyc.push_back(visitStack[db]);
                for(ll i = da; i!=dv; i += (dv-da)/abs(dv-da))
                    cyc.push_back(visitStack[i]);
                if(dv!=du) cyc.push_back(visitStack[dv]);
                printAns(cyc);
            }
            cyclesInStack.emplace_back(depth[v],depth[u]);
            
        }
    }
    trav(u,e[v]) if(!seen[u]) dfs(u,d+1);

    visitStack.pop_back();
    while(sz(cyclesInStack)&&cyclesInStack.back().first>=d) cyclesInStack.pop_back();
}

int main(){
    ll m;
    cin>>n>>m;
    e.resize(n);
    depth.resize(n);
    seen.resize(n);
    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        e[a-1].push_back(b-1);
        e[b-1].push_back(a-1);
    }
    rep(i,0,n) if(!seen[i]) dfs(i,0);
    cout<<"NO"<<endl;
}
