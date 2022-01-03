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
    ll n, m;
    cin >> n >> m;
    vector<ll> cards(m), rounds(n);
    rep(i, 0, n) cin >> rounds[i];
    rep(i, 0, m) cin >> cards[i];
    sort(all(cards));
    ll ans = inf;
    do
    {
        ll cur = 0;
        rep(i, 0, n) cur += abs(cards[i] - rounds[i]);
        ans = min(cur, ans);
    } while (next_permutation(all(cards)));
    cout << ans << endl;
    return 0;
}
