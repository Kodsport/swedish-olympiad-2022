#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) // ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;
vector<ll> ans_for_increasing(vector<ll> v, ll n, ll q)
{
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
  return ans;
}
vector<ll> ans_for_normal(vetor<ll> v, ll n, ll q)
{
  // just copy paste the actual solution I guess.
}
void run()
{
  int max_n = Arg("max_n");
  int max_q = Arg("max_q");
  int max_value = Arg("max_value");
  bool Arg("increasing", 0);
  int n = Int(1, max_n);
  int q = Int(1, max_q);
  Space();
  Endl();
  vi v = SpacedInts(n, 0, max_value);
  vi b(q);
  for (int i = 0; i < q; i++)
  {
    b[i] = Int(0, max_value);
    Endl();
  }
  vector<ll> ans1 = ans_for_increasing(v, n, q);
  vector<ll> ans2 = ans_for_normal(v, n, q);
  if (increasing)
  {
    for (int el : b)
    {
      if (el < n)
        assert(ans1[el] == ans2[el]);
    }
  }
  Eof();
}
