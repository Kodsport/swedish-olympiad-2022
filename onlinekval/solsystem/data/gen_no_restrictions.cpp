#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;
vector<string> args;
string cmdlinearg(string name, string def)
{
    trav(a, args)
    {
        if (a.size() < name.size() + 1)
            continue;
        bool good = 1;
        rep(i, 0, name.size())
        {
            if (a[i] != name[i])
            {
                good = 0;
                break;
            }
            if (a[name.size()] != '=')
                good = 0;
        }
        if (good)
        {
            string res = "";
            rep(i, name.size() + 1, a.size()) res += a[i];
            return res;
        }
    }
    if (def != "")
        return def;
    cout << "paremeter " << name << " not found" << endl;
    assert(0);
}
ll convert_to_int(string s)
{
    ll val = 0;
    reverse(all(s));
    ll power = 1;
    rep(i, 0, s.size()) val += power * (s[i] - '0'), power *= 10;
    return val;
}
int main(int argc, char **argv)
{
    // The areguments should be in this format:
    // seed=(seed) max_n=(max_n) max_r=(max_r) max_q=(max_q) max_r=(max_r) increasing=(increasing)
    rep(i, 0, argc) args.push_back(argv[i]);
    ll n = convert_to_int(cmdlinearg("max_n", ""));
    ll q = convert_to_int(cmdlinearg("max_q", ""));
    ll max_r = convert_to_int(cmdlinearg("max_r", ""));
    ll increasing = convert_to_int(cmdlinearg("increasing", "0"));
    ll seed = convert_to_int(cmdlinearg("seed", ""));
    srand(seed);
    cout << n << endl;
    if (increasing)
    {
        assert(n <= max_r);
        set<pair<ll, ll>> intervals;
        rep(i, 0, n)
        {
            while (true)
            {
                ll l = 1 + rand() % max_r;
                while (intervals.lower_bound(make_pair(l, -inf)) != intervals.end() && intervals.lower_bound(make_pair(l, -inf))->first == l)
                {
                    l = 1 + rand() % max_r;
                }
                auto it = intervals.lower_bound(make_pair(l, -inf));
                ll mx = max_r;
                ll mn = l;
                if (it != intervals.end())
                {
                    mx = min(max_r, it->second);
                }
                if (it != intervals.begin())
                {
                    it--;
                    mn = max(mn, it->second + 1);
                }
                if (mx <= mn)
                    continue;
                ll r = mn + rand() % (mx - mn);
                intervals.emplace(l, r);
                break;
            }
        }
        trav(a, intervals) cout << a.first << " " << a.second << endl;
    }
    else
    {
        rep(i, 0, n)
        {
            ll l = 1 + rand() % max_r;
            ll r = 1 + rand() % max_r;
            if (l > r)
                swap(l, r);
            cout << l << " " << r << endl;
        }
    }
    cout << q << endl;
    rep(i, 0, q)
    {
        ll A = 1 + rand() % max_r;
        ll B = 1 + rand() % max_r;
        while (A == B)
            B = 1 + rand() % max_r;
        cout << A << " " << B << endl;
    }
    return 0;
}