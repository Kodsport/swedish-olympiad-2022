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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    multiset<pair<ll, ll>> s;
    rep(i, 0, n)
    {
        ll m;
        cin >> m;
        set<pair<ll, ll>> intervals;
        rep(j, 0, m)
        {
            ll l, r;
            cin >> l >> r;
            intervals.emplace(l, r);
        }
        ll cur_l = -inf;
        ll cur_r = -inf;
        trav(interval, intervals)
        {
            if (interval.first > cur_r)
            {
                if (cur_l != -inf)
                {
                    s.emplace(cur_l, -1);
                    s.emplace(cur_r, 1);
                }
                cur_l = interval.first;
                cur_r = interval.second;
            }
            else
                cur_r = max(cur_r, interval.second);
        }
    }
    ll ans = 0;
    ll cur = 0;
    trav(a, s)
    {
        cur -= a.second;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
