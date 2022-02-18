#include <bits/stdc++.h>

typedef long long ll;
const long long inf = 2e9;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, Q;
    cin >> n >> Q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<ll>> stacks(n);
    vector<ll> closest(n, inf);
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= n)
            continue;
        stacks[v[i]].push_back(i);
        if (v[i])
        {
            while (stacks[v[i] - 1].size())
            {
                closest[stacks[v[i] - 1].back()] = i;
                stacks[v[i] - 1].pop_back();
            }
        }
    }
    queue<ll> q;
    vector<ll> started_from(n, -inf);
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            q.push(i);
            started_from[i] = i;
        }
    }
    vector<bool> visited(n);
    while (q.size())
    {
        ll cur = q.front();
        q.pop();
        ll nxt = closest[cur];
        if (nxt != inf)
        {
            if (!visited[nxt])
            {
                q.push(nxt);
                visited[nxt] = 1;
            }
            started_from[nxt] = max(started_from[nxt], started_from[cur]);
        }
    }
    vector<ll> ans(n, inf);
    for (int i = 0; i < n; i++)
    {
        if (v[i] < n)
            ans[v[i]] = min(ans[v[i]], i - started_from[i] + 1);
    }
    for (int i = 0; i < Q; i++)
    {
        ll a;
        cin >> a;
        if (a >= n)
            cout << -1;
        else
            cout << (ans[a] == inf ? -1 : ans[a]);
        cout << '\n';
    }
    return 0;
}
