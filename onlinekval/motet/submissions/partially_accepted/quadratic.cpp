#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(1e3);
    rep(i, 0, n)
    {
        ll m;
        cin >> m;
        vector<bool> visited(1e3);
        rep(j, 0, m)
        {
            ll a, b;
            cin >> a >> b;
            rep(r, a, b + 1) visited[r] = 1;
        }
        rep(r, 0, 1e3) v[r] += visited[r];
    }
    ll ans = 0;
    trav(a, v) ans = max(ans, a);
    cout << ans << endl;
    return 0;
}
