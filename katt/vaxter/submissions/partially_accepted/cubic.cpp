#include <bits/stdc++.h>

typedef long long ll;
const long long inf = 2e9;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n), res(n, inf);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll cur = -1;
            vector<ll> counter(n);
            for (int r = j; r < n; r++)
            {
                counter[v[r]]++;
                while (cur + 1 < n && counter[cur + 1])
                    cur++;
                if (cur >= i)
                {
                    res[i] = min(res[i], (ll)r - j + 1);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        ll a;
        cin >> a;
        if (a >= n || res[a] == inf)
            cout << -1 << '\n';
        else
            cout << res[a] << '\n';
    }
    return 0;
}
