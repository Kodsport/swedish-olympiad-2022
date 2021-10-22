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

vector<vector<pair<ll, ll>>> disjoint(ll n, ll min_m, ll max_m, ll sum_m, ll max_coordinate)
{

        assert(max_coordinate / 2 >= min_m);
        assert(min_m * n <= sum_m && max_m * n >= sum_m);

    vector<set<ll>> temp_vec(n);
    vector<vector<pair<ll, ll>>> vec(n);
    queue<pair<ll, ll>> available;
    rep(i, 0, n)
    {
        ll m = min_m + rand() % min(sum_m - min_m * (n - i) + 1, min(sum_m - min_m + 1, max_m - min_m + 1));
        sum_m -= m;
        available.emplace(max_m - m, i);
        m *= 2;
        while (m--)
        {
            ll a = rand() % (max_coordinate + 1);
            while (temp_vec[i].find(a) != temp_vec[i].end())
                a = rand() % max_coordinate + 1;
            temp_vec[i].insert(a);
        }
    }
    while (sum_m--)
    {
        if (available.front().first == 0)
        {
            sum_m++;
            available.pop();
            continue;
        }
        ll a = rand() % (max_coordinate + 1);
        rep(i, 0, 2)
        {
            while (temp_vec[available.front().second].find(a) != temp_vec[available.front().second].end())
                a = rand() % max_coordinate + 1;
            temp_vec[available.front().second].insert(a);
        }
        available.front().first--;
    }
    rep(i, 0, n)
    {
        set<pair<ll, pair<ll, ll>>> intervals;
        auto it = temp_vec[i].begin();
        while (it != temp_vec[i].end())
        {
            ll w = rand() % 1000000000; // just so that they're sorted randomly
            ll l = *it;
            it++;
            intervals.emplace(w, make_pair(l, *it));
            it++;
        }
        trav(a, intervals) vec[i].push_back(a.second);
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
    srand(seed);
    max_coordinate = convert_to_int(cmdlinearg("max_coordinate"));
    set_n(n, sum_m, max_m, min_m, type_of_n);
    cout << n << endl;
    vector<vector<pair<ll, ll>>> vec = disjoint(n, min_m, max_m, sum_m, max_coordinate);
    trav(v, vec)
    {
        cout << v.size() << " ";
        trav(a, v)
        {
            if (a.first > a.second)
                swap(a.first, a.second);
            cout << a.first << " " << a.second << " ";
        }

        cout << endl;
    }
    return 0;
}