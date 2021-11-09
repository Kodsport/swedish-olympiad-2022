#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;
struct Tree
{
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; } // (any associative fn)
    vector<T> s;
    int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val)
    {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e)
    { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2)
        {
            if (b % 2)
                ra = f(ra, s[b++]);
            if (e % 2)
                rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
bool in_interval(pair<ll, ll> a, ll val)
{
    return a.first <= val && val <= a.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    map<ll, ll> mapping;
    set<ll> coordinates;
    ll counter = 0;
    rep(i, 0, n)
    {
        cin >> v[i].first >> v[i].second;
        coordinates.insert(v[i].first);
        coordinates.insert(v[i].second);
    }
    ll Q;
    cin >> Q;
    vector<pair<pair<ll, ll>, ll>> q(Q);
    rep(i, 0, Q)
    {
        cin >> q[i].first.first >> q[i].first.second;
        if (q[i].first.first > q[i].first.second)
            swap(q[i].first.first, q[i].first.second);
        q[i].second = i;
        coordinates.insert(q[i].first.first);
        coordinates.insert(q[i].first.second);
    }
    trav(a, coordinates) mapping[a] = counter++;
    trav(a, q)
    {
        a.first.first = mapping[a.first.first];
        a.first.second = mapping[a.first.second];
    }
    trav(a, v)
    {
        a.first = mapping[a.first];
        a.second = mapping[a.second];
    }
    Tree tree(counter);
    Tree tree0 = tree;
    priority_queue<pair<ll, ll>> pq;
    sort(all(q));
    rep(i, 0, n)
    {
        pq.emplace(-v[i].first, v[i].second);
    }
    vector<ll> ans(Q);
    rep(i, 0, Q)
    {
        while (pq.size() && abs(pq.top().first) <= q[i].first.first)
        {
            tree.update(pq.top().second, tree.query(pq.top().second, pq.top().second + 1) + 1);
            pq.pop();
        }
        ans[q[i].second] += tree.query(q[i].first.first, q[i].first.second);
    }
    priority_queue<pair<ll, ll>> pq0;
    pq = pq0;
    rep(i, 0, n)
    {
        pq.emplace(v[i].second, v[i].first);
    }
    rep(i, 0, Q)
    {
        swap(q[i].first.first, q[i].first.second);
        q[i].first.first *= -1;
    }
    sort(all(q));
    tree = tree0;
    rep(i, 0, Q)
    {
        while (pq.size() && pq.top().first >= abs(q[i].first.first))
        {
            tree.update(pq.top().second, tree.query(pq.top().second, pq.top().second + 1) + 1);
            pq.pop();
        }
        ans[q[i].second] += tree.query(q[i].first.second + 1, -q[i].first.first + 1);
    }
    trav(a, ans) cout << a << endl;
    return 0;
}
