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
    // seed=(seed) max_value=(max_value) max_value=(max_value) n=(n) plus_one(1 or 0)
    // plus_one is a boolean to know if data should be generated for the subtask in which there are N cards
    rep(i, 0, argc) args.push_back(argv[i]);
    ll seed = convert_to_int(cmdlinearg("seed"));
    srand(seed);
    ll max_value = convert_to_int(cmdlinearg("max_value"));
    ll plus_one = convert_to_int(cmdlinearg("plus_one"));
    ll n = convert_to_int(cmdlinearg("max_n"));
    cout << n << " " << n + plus_one << endl;
    rep(i, 0, n)
    {
        cout << rand() % (max_value + 1) << (i + 1 == n ? "" : " ");
    }
    cout << endl;
    rep(i, 0, n + plus_one)
    {
        cout << rand() % (max_value + 1) << (i + 1 == (n + plus_one) ? "" : " ");
    }
    cout << endl;
    return 0;
}
