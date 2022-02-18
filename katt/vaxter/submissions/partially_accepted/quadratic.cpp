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
        ll l = 0;
        ll cur = -1;
        vector<ll> counter(n);
        for (int j = 0; j < n; j++)
        {
            counter[v[j]]++;
            while (cur + 1 < n && counter[cur + 1])
                cur++;
            while (cur >= i)
            {
                res[i] = min(res[i], j - l + 1);
                counter[v[l]]--;
                if (counter[v[l]] == 0)
                    cur = min(cur, v[l] - 1);
                l++;
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
