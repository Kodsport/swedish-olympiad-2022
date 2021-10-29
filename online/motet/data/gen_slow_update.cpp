#include <bits/stdc++.h>

// This test group is to counter bruteforce O(size_of_interval) update when doing coordinate-compression
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
void set_n(ll &n, ll sum_m, ll max_m, ll min_m, ll type_of_n)
{
    if (type_of_n == 1)
        n = 1;
    else if (type_of_n == 2)
        n = sqrt(sum_m);
    else if (type_of_n == 3)
        n = sum_m;
    else
        n = (sum_m + max_m - (sum_m % max_m)) / max_m + rand() % (sum_m / (min_m ? min_m : 1) - sum_m / max_m);
}

vector<vector<pair<ll, ll>>> slow_update(ll n, ll min_m, ll max_m, ll sum_m, ll max_coordinate)
{
    vector<vector<pair<ll, ll>>> vec(n);
    ll l = max_coordinate / 2;
    ll r = (max_coordinate + 1) / 2;
    rep(i, 0, n)
    {
        vec[i].emplace_back(l, r);
        l = max(l - 1, (ll)0);
        r = min(r + 1, max_coordinate);
    }
    return vec;
}
int main(int argc, char **argv)
{
    // The areguments should be in this format:
    // seed=(seed) sum_m=(sum_m) max_m=(max_m) min_m=(max_m) max_coordinate=(max_coordinate) type_of_n=(type_of_n)
    // types of n: 1 -> n=1 , 2 -> n= sqrt(sum_m), 3 -> n=sum_m , other->random
    rep(i, 0, argc) args.push_back(argv[i]);
    ll seed, n, sum_m, max_coordinate, max_m, min_m, type_of_n;
    type_of_n = convert_to_int(cmdlinearg("type_of_n"));
    min_m = convert_to_int(cmdlinearg("min_m"));
    max_m = convert_to_int(cmdlinearg("max_m"));
    sum_m = convert_to_int(cmdlinearg("sum_m"));
    seed = convert_to_int(cmdlinearg("seed"));
    max_coordinate = convert_to_int(cmdlinearg("max_coordinate"));
    srand(seed);
    set_n(n, sum_m, max_m, min_m, type_of_n);
    vector<vector<pair<ll, ll>>> vec = slow_update(n, min_m, max_m, sum_m, max_coordinate);
    cout
        << n << endl;
    trav(v, vec)
    {
        cout << v.size() << " ";
        rep(i, 0, v.size())
        {
            pair<ll, ll> a = v[i];
            if (a.first > a.second)
                swap(a.first, a.second);
            cout << a.first << " " << a.second << (i + 1 == v.size() ? "" : " ");
        }

        cout << endl;
    }
    return 0;
}