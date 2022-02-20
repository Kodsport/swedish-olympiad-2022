#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
const long long inf = 2e9;

using namespace std;
vector<string> args;
string cmdlinearg(string name, string defaul = "")
{
    for (auto a : args)
    {
        if ((int)a.size() < (int)name.size() + 1)
            continue;
        bool good = 1;
        for (int i = 0; i < (int)name.size(); i++)
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
            for (int i = name.size() + 1; i < (int)a.size(); i++)
                res += a[i];
            return res;
        }
    }
    if (defaul != "")
        return defaul;
    cout << "paremeter " << name << " not found" << endl;
    assert(0);
}
ll convert_to_int(string s)
{
    ll val = 0;
    reverse(s.begin(), s.end());
    ll power = 1;
    for (int i = 0; i < (int)s.size(); i++)
        val += power * (s[i] - '0'), power *= 10;
    return val;
}
vector<ll> equally_frequent(ll n, ll max_value)
{
    vector<ll> v;
    ll left = n;
    max_value++;
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
    assert((long long)v.size() == n);
    return v;
}
int main(int argc, char **argv)
{
    // The areguments should be in this format: seed, max_value, max_n, max_q, slump, type;
    // slump is a boolean that decides whether the queries are gonna be generated randomally
    // types:
    // type=1 -> random, type=2 -> sorted equally frequent elements
    // type=3 -> randomly suffled equally sorted elements
    for (int i = 0; i < argc; i++)
        args.push_back(argv[i]);
    ll seed = convert_to_int(cmdlinearg("seed"));
    srand(seed);
    ll max_value = convert_to_int(cmdlinearg("max_value"));
    ll type = convert_to_int(cmdlinearg("type"));
    ll slump = convert_to_int(cmdlinearg("slump", "0"));
    ll n = convert_to_int(cmdlinearg("max_n"));
    ll q = convert_to_int(cmdlinearg("max_q"));
    bool queryone = convert_to_int(cmdlinearg("queryone", "0"));
    cout << n << " " << q << endl;
    vector<ll> res;
    if (type == 1)
    {
        for (int i = 0; i < n; i++)
            res.push_back(rand() % (max_value + 1));
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
    cout << endl;
    if (queryone)
    {
        assert(q == 1);
        cout << 1 << endl;
        return 0;
    }
    if (slump)
    {
        for (int i = 0; i < q; i++)
            cout << rand() % (max_value + 1) << '\n';
    }
    else
    {
        for (int i = 0; i < q; i++)
            cout << min((int)max_value, i) << '\n';
    }
    return 0;
}
