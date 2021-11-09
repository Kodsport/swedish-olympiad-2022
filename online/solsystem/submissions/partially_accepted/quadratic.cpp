#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;
bool in_interval(pair<ll, ll> a, ll val)
{
    return a.first <= val && val <= a.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    rep(i, 0, n) cin >> v[i].first >> v[i].second;
    ll q;
    cin >> q;
    rep(i, 0, q)
    {
        ll ans = 0;
        ll A, B;
        cin >> A >> B;
        trav(a, v) ans += in_interval(a, A) ^ in_interval(a, B);
        cout << ans << endl;
    }
    return 0;
}
