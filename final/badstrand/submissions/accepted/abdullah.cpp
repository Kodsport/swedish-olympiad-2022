#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e15;

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, 0, n) cin >> v[i];
    ll ans = 0;
    ll sum = 0;
    ll j = 0; // First element of the current subsegment
    rep(i, 0, n)
    {
        sum += v[i];
        while (sum > k)
        {
            sum -= v[j];
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << max(ans, n - j) << endl;
    return 0;
}
