#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 1234567890123456789;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl
#define sz(x) ((int)(x).size())

int n, k;
vvi adj;
vector<double> damage;
vector<double> ans;

vector<double> up;
vector<double> down;
double dfs(int v, int p) {
    double sum = 0;
    for (auto u : adj[v]) {
        if (u == p) continue;
        sum += dfs(u, v);
    }
    ans[v] = damage[v] + sum;
    for (auto u : adj[v]) {
        if (u == p) continue;
        down[u] = (sz(adj[v]) == 1 ? 0 : (sum - up[u]) / (sz(adj[v]) - 1)) + damage[v] / sz(adj[v]);
    }
    up[v] = (sz(adj[v]) == 1 ? 0 : sum / (sz(adj[v]) - 1)) + damage[v] / sz(adj[v]);
    return up[v];
}

void dfs2(int v, int p, double w) {
    w += down[v];
    ans[v] += w;
    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs2(u, v, w / (sz(adj[v]) - (p != -1)));
    }
}

void solve() {
    ans = up = down = vector<double>(n);
    dfs(0, -1);
    dfs2(0, -1, 0);
}

int main() {
    cin>>n;

    cout<<fixed<<setprecision(20);
    adj = vvi(n);
    for (int i = 1; i < n; i++) {
        int u,v;
        cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    cin>>k;
    damage = vector<double>(n);
    for (int i = 0; i < k; i++) {
        int u,power;
        cin>>u>>power;
        damage[u-1] += power;
    }

    solve();
    for (int i = 0; i < n; i++) cout<<ans[i]<<endl;
}