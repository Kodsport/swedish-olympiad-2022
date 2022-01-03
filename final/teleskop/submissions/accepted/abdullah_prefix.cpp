#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e15;

using namespace std;
ll dist(ll next, ll cur)
{
    if (next < cur)
        swap(next, cur);
    return min(next - cur, (359 - next + cur));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, 0, n) cin >> v[i];
    vector<ll> vec;
    rep(i, 0, n - 1) vec.push_back(dist(v[i], v[i + 1]));
    vector<ll> prefix(vec.size() + 1);
    rep(i, 1, prefix.size())
    {
        prefix[i] = prefix[i - 1] + vec[i - 1];
    }
    ll ans = 0;
    rep(i, 0, prefix.size())
    {
        ll next = upper_bound(all(prefix), k + prefix[i]) - prefix.begin();
        ans = max(ans, next - i);
    }
    cout << ans << endl;
    return 0;
}
