#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;
int main(int argc, char **argv)
{
    ll sum_m, max_coordinate, min_m, max_m;
    // Arguments: sum_m max_m  min_m max_coordinate
    vector<ll> v;
    rep(i, 1, argc)
    {
        stringstream ss;
        ss << argv[i];
        ll val;
        ss >> val;
        v.push_back(val);
    }
    sum_m = v[0];
    max_m = v[1];
    min_m = v[2];
    max_coordinate = v[3];
    ll n;
    cin >> n;
    ll sum = 0;
    bool min_m_satisfied = 1, disjoint = 1, max_m_satisfied = 1, max_coordinate_satisfied = 1;
    bool length_greater_than_zero = 1;
    rep(i, 0, n)
    {
        ll m;
        cin >> m;
        sum += m;
        min_m_satisfied = min_m_satisfied && (m >= min_m);
        max_m_satisfied = max_m_satisfied && (m <= max_m);
        set<pair<ll, ll>> intervals;
        rep(j, 0, m)
        {
            ll l, r;
            cin >> l >> r;
            if (max(l, r) > max_coordinate)
                max_coordinate_satisfied = 0;
            intervals.emplace(l, r);
            length_greater_than_zero = ((r - l + 1) > 0) && length_greater_than_zero;
        }
        ll last_r = -inf;
        trav(a, intervals)
        {
            if (last_r >= a.first)
                disjoint = 0;
            last_r = max(a.second, last_r);
        }
    }
    bool good = 1;
    if (!length_greater_than_zero || sum != sum_m || !min_m_satisfied || !max_m_satisfied || !max_coordinate_satisfied)
    {
        cout << "bad" << endl;
        good = 0;
    }
    else
        cout << "good" << endl;
    if (!length_greater_than_zero)
    {
        cout << "length less or equal to zero in some interval" << endl;
    }
    if (!min_m_satisfied)
    {
        cout << "min_m not satisified" << endl;
    }
    if (!max_m_satisfied)
    {
        cout << "max_m not satisfied" << endl;
    }
    if (!max_coordinate_satisfied)
    {
        cout << "max_coordinate not satisfied" << endl;
    }
    if (sum != sum_m)
    {
        cout << "sum_m not satisfied" << endl;
    }
    if (disjoint)
        cout << "disjoint" << endl;
    else
        cout << "not disjoint" << endl;
    assert(good);
    return 0;
}
