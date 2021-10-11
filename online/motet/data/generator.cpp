#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;
vector<vector<pair<ll, ll>>> disjoint(ll n, ll min_m, ll max_m, ll sum_m, ll max_coordinate)
{

    if (max_coordinate / 2 < min_m)
    {
        cout << "Impossible conditionns regarding max_coordinate sum_m or n" << endl;
        assert(0);
    }
    if (max_m > max_coordinate / 2)
    {
        cout << "max_m is effectively less than what is wanted becuase of too low max_coordinate" << endl;
        assert(0);
    }
    if (min_m * n > sum_m || max_m * n < sum_m)
    {
        cout << "Impossible conditions regarding max_m,min_m sum_m or n" << endl;
        assert(0);
    }

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
vector<vector<pair<ll, ll>>> no_restrictions(ll n, ll min_m, ll max_m, ll sum_m, ll max_coordinate)
{
    if (max_coordinate / 2 < min_m)
    {
        cout << "Impossible conditionns regarding max_coordinate sum_m or n" << endl;
        assert(0);
    }
    if (max_m > max_coordinate / 2)
    {
        cout << "max_m is effectively less than what is wanted becuase of too low max_coordinate" << endl;
        assert(0);
    }
    if (min_m * n > sum_m || max_m * n < sum_m)
    {
        cout << "Impossible conditions regarding max_m,min_m sum_m or n" << endl;
        assert(0);
    }
    vector<vector<pair<ll, ll>>> vec(n);
    queue<pair<ll, ll>> available;
    rep(i, 0, n)
    {
        ll m = min_m + rand() % min(sum_m - min_m * (n - i) + 1, min(sum_m - min_m + 1, max_m - min_m + 1));
        sum_m -= m;
        available.emplace(max_m - m, i);
        rep(j, 0, m)
        {
            vec[i].push_back(make_pair(rand() % (max_coordinate + 1), rand() % (max_coordinate + 1)));
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
        vec[available.front().second].push_back(make_pair(rand() % (max_coordinate + 1), rand() % (max_coordinate + 1)));
        available.front().first--;
    }
    return vec;
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
vector<vector<pair<ll, ll>>> all_length_disjoint(ll n, ll max_coordinate)
{
    vector<vector<pair<ll, ll>>> vec(n);
    rep(i, 0, n)
    {
        vec[i].emplace_back(0, max_coordinate);
    }
    return vec;
}
vector<vector<pair<ll, ll>>> all_length(ll n, ll min_m, ll max_m, ll sum_m, ll max_coordinate)
{
    if (max_coordinate / 2 < min_m)
    {
        cout << "Impossible conditionns regarding max_coordinate sum_m or n" << endl;
        assert(0);
    }
    if (max_m > max_coordinate / 2)
    {
        cout << "max_m is effectively less than what is wanted becuase of too low max_coordinate" << endl;
        assert(0);
    }
    if (min_m * n > sum_m || max_m * n < sum_m)
    {
        cout << "Impossible conditions regarding max_m,min_m sum_m or n" << endl;
        assert(0);
    }
    queue<pair<ll, ll>> available;
    vector<vector<pair<ll, ll>>> vec(n);
    rep(i, 0, n)
    {
        ll m = min_m + rand() % min(sum_m - min_m + 1, max_m - min_m + 1);
        sum_m -= m;
        available.emplace(max_m - m, i);
        rep(j, 0, m)
        {
            vec[i].push_back(make_pair(0, max_coordinate));
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
        vec[available.front().second].push_back(make_pair(rand() % (max_coordinate + 1), rand() % (max_coordinate + 1)));
        available.front().first--;
    }
    return vec;
}
ll n, sum_m, max_coordinate, max_m, min_m, type_of_n;
void set_n(ll &n, ll sum_m, ll type_of_n)
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
int main(int argc, char **argv)
{
    // The areguments should be in this form:
    // the_type_of_testcase The_seed sum_m max_m min_m max_coordinate type_of_n
    //types of testcases: look below
    // types of n: 1 -> n=1 , 2 -> n= sqrt(sum_m), 3 -> random
    vector<ll> v;
    rep(i, 2, argc)
    {
        stringstream ss;
        ss << argv[i];
        ll val;
        ss >> val;
        v.push_back(val);
    }
    ll N;
    N = v[0];
    sum_m = v[1];
    max_m = v[2];
    min_m = v[3];
    max_coordinate = v[4];
    type_of_n = v[5];
    set_n(n, sum_m, type_of_n);
    srand(N);
    vector<vector<pair<ll, ll>>> vec;
    string type_of_test_case = argv[1];
    if (type_of_test_case == "disjoint")
    {
        vec = disjoint(n, min_m, max_m, sum_m, max_coordinate);
    }
    else if (type_of_test_case == "all_length")
    {
        vec = all_length(n, min_m, max_m, sum_m, max_coordinate);
    }
    else if (type_of_test_case == "no_restrictions")
    {
        vec = no_restrictions(n, min_m, max_m, sum_m, max_coordinate);
    }
    else if (type_of_test_case == "slow_update")
    {
        vec = slow_update(n, min_m, max_m, sum_m, max_coordinate);
    }
    else if (type_of_test_case == "all_length_disjoint")
    {
        vec = all_length_disjoint(n, max_coordinate);
    }
    else
    {
        cout << type_of_test_case << " is an invalid type_of_test_case" << endl;
        assert(0);
    }
    cout << n << endl;
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
