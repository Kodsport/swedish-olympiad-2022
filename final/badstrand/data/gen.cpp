#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

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
int main(int argc, char **argv)
{
    // The areguments should be in this format:
    // seed=(seed) max_k=(max_k) max_n=(max_n)
    rep(i, 0, argc) args.push_back(argv[i]);
    ll seed = convert_to_int(args[argc-1]);
    srand(seed);
    ll max_a = convert_to_int(cmdlinearg("max_a"));
    ll n = convert_to_int(cmdlinearg("max_n"));
    ll ans = convert_to_int(cmdlinearg("ans"));

    vector<ll> as;
    rep(i,0,n) as.push_back(rand()%1000 + 1);

    set<ll> s;
    rep(i,0,ans) s.insert(a[i]);
    ll b = *s.begin();
    rep(i,0,)

    cout << n << " " << rand() % (max_k + 1) << endl;
    rep(i, 0, n)
    {
        cout << rand() % 360 << (i + 1 == n ? "" : " ");
    }
    cout << endl;
    return 0;
}
