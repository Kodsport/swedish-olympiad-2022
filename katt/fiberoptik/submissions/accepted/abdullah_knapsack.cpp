#include <bits/stdc++.h>

typedef long long ll;
const long long inf = 2e9;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll root = 0;
    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        g[i + 1].push_back(make_pair(a, -b));
        g[a].push_back(make_pair(i + 1, -b));
    }
    vector<ll> parents(n);
    vector<vector<pair<ll, ll>>> children(n);
    queue<ll> q;
    q.push(root);
    vector<bool> visited(n);
    visited[root] = 1;
  // Makes the tree rooted
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        for (auto &a : g[cur])
        {
            ll next = a.first;
            if (!visited[next])
            {
                parents[next] = cur;
                children[cur].push_back(a);
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (children[i].size() == 0)
            q.push(i);
    vector<pair<ll, ll>> a(n), b(n); // a[i] is the best answer for i when at most k edges are used, b[i] is best answer for i when at most k-1 are used
    vector<ll> counter(n);
  // Bottom-up dp
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        vector<pair<ll, ll>> dp(k + 1, make_pair(-inf, -inf));
        counter[parents[cur]]++;
        if (counter[parents[cur]] == children[parents[cur]].size())
            q.push(parents[cur]);
        dp[0] = make_pair(0, 0);
        for (pair<ll, ll> child : children[cur])
        {
            ll id = child.first, w = child.second;
            for (int i = k; i >= 0; i--)
            {
                if (i < k)
                    dp[i + 1] = max(dp[i + 1], make_pair(dp[i].first + b[id].first + 1, dp[i].second + b[id].second + w));
                dp[i] = max(dp[i], make_pair(dp[i].first + a[id].first, dp[i].second + a[id].second)); 
            }
        }
        a[cur] = *max_element(dp.begin(), dp.begin() + k + 1);
        b[cur] = *max_element(dp.begin(), dp.begin() + k);
    }
    pair<ll, ll> ans = max(a[0], b[0]);
    cout << ans.first << " " << -ans.second << endl;
    return 0;
}
