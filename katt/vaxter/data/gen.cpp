#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
const long long inf = 2e9;

using namespace std;
vector<string> args;
string cmdlinearg(string name)
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
vector<ll> equally_frequent(ll n, ll max_value)
{
    vector<ll> v;
    ll left = n;
    for (int i = 0; i < max_value; i++)
    {
        for (int j = 0; j < ((n + max_value - 1) / max_value); j++)
        {
            if (!left)
                break;
            left--;
            v.push_back(i);
        }
        if (!left)
            break;
    }
    assert(v.size() == n);
    return v;
}
int main(int argc, char **argv)
{
    // The areguments should be in this format: seed, max_value, max_n, max_q, slump, type;
    // slump is a boolean that decides whether the queries are gonna be generated randomally
    // types:
    // type=1 -> random, type=2 -> sorted equally frequent elements
    // type=3 -> randomly suffled equally sorted elements, type=4 -> an optimal answer always exists with the an increasing sequence
    rep(i, 0, argc) args.push_back(argv[i]);
    ll seed = convert_to_int(cmdlinearg("seed"));
    srand(seed);
    ll max_value = convert_to_int(cmdlinearg("max_value"));
    ll type = convert_to_int(cmdlinearg("type"));
    ll slump = convert_to_int(cmdlinearg("slump"));
    ll n = convert_to_int(cmdlinearg("max_n"));
    ll q = convert_to_int(cmdlinearg("max_q"));
    cout << n << " " << q << endl;
    vector<ll> res;
    if (type == 1)
    {
        for (int i = 0; i < n; i++)
            res.push_back(rand() % max_value);
    }
    else if (type == 2)
    {
        res = equally_frequent(n, max_value);
    }
    else if (type == 3)
    {
        res = equally_frequent(n, max_value);
        random_shuffle(res.begin(), res.end());
    }
    else
    {
        cerr << "Invalid \"type\" argument \n";
        assert(0);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << (i + 1 == n ? "" : " ");
    if (slump)
    {
        for (int i = 0; i < q; i++)
            cout << rand() % max_value << '\n';
    }
    else
    {
        for (int i = 0; i < q; i++)
            cout << i << '\n';
    }
    return 0;
}
