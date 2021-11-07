#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b - 1); i >= (a); --i)
#define trav(a, x) for (auto &a : x)

#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl

#define umap unordered_map
#define uset unordered_set

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cout << fixed << setprecision(20);
    int n, k;
    double sum_all = 0, sum_node[100001];
    fill(sum_node, sum_node + 100001, 0);

    cin >> n;
    int u, v, power;

    rep(i, 0, n - 1) cin >> u >> v;
    

    cin >> k;
    rep(i, 0, k) {
        cin >> u >> power;
        --u;
        if (u&&u<n-1) {
            sum_all += power / 2.0;
            sum_node[u] += power / 2.0;
        } else
            sum_all += power;
    }

    rep(i, 0, n) cout << sum_all + sum_node[i] << endl;
    return 0;
}