#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

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
    ll ans = 0;
    rep(i, 0, n)
    {
        ll sum = 0;
        bool good = 1;
        rep(j, i, n - 1)
        {
            ans = max(ans, (ll)j - i + 1);
            sum += dist(v[j], v[j + 1]);
            if (sum > k)
            {
                good = 0;
                break;
            }
        }
        if (good)
            ans = max(ans, n - i);
    }
    cout << ans << endl;
    return 0;
}
