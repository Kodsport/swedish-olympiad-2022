#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
const long long inf = 2e9;
const long long inff = 2e9 + 10;
using namespace std;
struct Node
{
    Node *l = 0, *r = 0;
    int lo, hi, mset = inff, madd = 0, val = -inf;
    Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of -inf
    Node(vector<ll> &v, int lo, int hi) : lo(lo), hi(hi)
    {
        if (lo + 1 < hi)
        {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else
            val = v[lo];
    }
    ~Node()
    {
        delete l;
        delete r;
    }
    int query(int L, int R)
    {
        if (R <= lo || hi <= L)
            return -inf;
        if (L <= lo && hi <= R)
            return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x)
    {
        if (R <= lo || hi <= L)
            return;
        if (L <= lo && hi <= R)
            mset = val = x, madd = 0;
        else
        {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x)
    {
        if (R <= lo || hi <= L)
            return;
        if (L <= lo && hi <= R)
        {
            if (mset != inff)
                mset += x;
            else
                madd += x;
            val += x;
        }
        else
        {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push()
    {
        if (mset != inff)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inff;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};
struct update
{
    ll time_stamp, r, size;
    bool operator<(update a)
    {
        if (time_stamp != a.time_stamp)
            return time_stamp < a.time_stamp;
        if (r != a.r)
            return r < a.r;
        if (size != a.size)
            return size < a.size;
    }
};
// Gets the nearest index whose value is greater than seg_tree[L]. Works in LogN LogN and could be cut down to to LogN with precomputing
ll get_next(ll L, ll R, ll val, Node *seg_tree)
{
    ll l = 1, r = R - L;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (seg_tree->query(L, L + mid) > val)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return L + r;
}
ll n, q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    vector<ll> v(n);
    vector<vector<ll>> wher(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] < n)
            wher[v[i]].push_back(i);
    }
    vector<ll> counter(n);
    vector<vector<update>> updates(n);
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < n)
            counter[v[i]]++;
        while (cur < n && counter[cur])
        {
            updates[cur].push_back({0, i, i + 1});
            cur++;
        }
    }
    vector<ll> pointers(n);
    for (int i = 0; i < n; i++)
    {
        if (v[i] < n)
        {
            if (pointers[v[i]] + 1 == wher[v[i]].size())
            {
                updates[v[i]].push_back({i + 1, inf, inf});
            }
            else
            {
                pointers[v[i]]++;
                updates[v[i]].push_back({i + 1, wher[v[i]][pointers[v[i]]], wher[v[i]][pointers[v[i]]] - i});
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (updates[i].size() == 0)
            updates[i].push_back({0, inf, inf});
    // So now I have the updates which are: set the suffix startig i to update[i][j].r.
    vector<ll> init(n + 1, inf);
    Node *seg_tree = new Node(init, 0, n + 1);
    Node *res_seg_tree = new Node(init, 0, n + 1); // This segtree should be a min segtree so I just take negative everything
    seg_tree->set(0, n + 1, updates[0][0].r);
    res_seg_tree->set(0, n + 1, -inf);
    res_seg_tree->set(updates[0][0].r - 1, updates[0][0].r, -1);
    vector<ll> ans(n);
    cur = 1;
    // Initializes the segtrees for 0. Could probably merged to the next loop to make the code clenear
    for (int i = 1; i < n + 1; i++)
    {
        if (cur < updates[0].size() && updates[0][cur].time_stamp == i)
        {
            ll nxt = cur + 1 == updates[0].size() ? n + 1 : updates[0][cur + 1].time_stamp;
            seg_tree->set(i, nxt, updates[0][cur].r);
            res_seg_tree->set(nxt - 1, nxt, -(updates[0][cur].r - nxt + 2));
            if (i)
            {
                res_seg_tree->set(i - 1, i, -(seg_tree->query(i - 1, i) - i + 2));
            }
            if (i < nxt - 1)
            {
                res_seg_tree->set(i, nxt - 1, -inf);
            }

            cur++;
        }
    }
    ans[0] = -res_seg_tree->query(0, n + 1);
    // continues wiht the updates for other values
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < updates[i].size(); j++)
        {
            update el = updates[i][j];
            ll nxt = j + 1 == updates[i].size() ? n + 1 : updates[i][j + 1].time_stamp;
            ll actual_next = get_next(el.time_stamp, nxt, el.r, seg_tree);

            if (el.r >= seg_tree->query(el.time_stamp, actual_next))
            {
                seg_tree->set(el.time_stamp, actual_next, el.r);
            }
            res_seg_tree->set(actual_next - 1, actual_next, -(el.r - actual_next + 2)); // The last index updated is the only relavent one
            if (el.time_stamp)
                res_seg_tree->set(el.time_stamp - 1, el.time_stamp, -(seg_tree->query(el.time_stamp - 1, el.time_stamp) - el.time_stamp + 2)); // push updates that may disappear backwards
            if (el.time_stamp < actual_next - 1)
            {
                res_seg_tree->set(el.time_stamp, actual_next - 1, -inf);
            }
        }
        ans[i] = -res_seg_tree->query(0, n + 1);
    }
    for (int i = 0; i < q; i++)
    {
        ll a;
        cin >> a;
        if (a >= n || abs(ans[a]) > n)
            cout << -1 << '\n';
        else
            cout << ans[a] << '\n';
    }
    delete seg_tree;
    delete res_seg_tree;
    return 0;
}
