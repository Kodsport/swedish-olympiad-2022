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
ll r, c, seed;
void random_with_probability(ll probability) // type=1
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            if (rand() % 100 < probability)
                cout << '#';
            else
                cout << '.';
        cout << endl;
    }
}
void counter_heuristic() // type=2
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((i % 2 == 0) || (i == r - 1) || j == 0 || j == c - 1)
                cout << '.';
            else
                cout << '#';
        }
        cout << endl;
    }
}
void random_with_n(ll n, ll probability) // type=3
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((i != 0 || j != 0) and (i != r - 1 || j != c - 1) and n and rand() % 100 < probability)
            {
                cout << '#';
                n--;
            }
            else
                cout << '.';
        }
        cout << endl;
    }
}
vector<pair<ll, ll>> change = {make_pair(0, 1), make_pair(0, -1), make_pair(-1, 0), make_pair(1, 0)};
bool inside(ll cur_r, ll cur_c)
{
    return cur_r >= 0 and cur_c >= 0 and cur_r < r and cur_c < c;
}
bool dfs(ll cur_r, ll cur_c, vector<vector<bool>> &visited, vector<vector<bool>> &on_path)
{

    if (cur_r == r - 1 and cur_c == c - 1)
    {
        on_path[cur_r][cur_c] = 1;
        return 1;
    }
    visited[cur_r][cur_c] = 1;
    vector<pair<ll, ll>> change2 = change;
    unsigned seed2 = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(change2.begin(), change2.end(), default_random_engine(seed2));
    for (int i = 0; i < 4; i++)
    {
        ll next_r = cur_r + change2[i].first;
        ll next_c = cur_c + change2[i].second;
        if (inside(next_r, next_c) and !visited[next_r][next_c])
            if (dfs(next_r, next_c, visited, on_path))
            {
                on_path[cur_r][cur_c] = 1;
                return 1;
            }
    }

    return 0;
}

void generate_two_paths(ll probability) // type=4
{
    vector<vector<bool>> visited(r, vector<bool>(c));
    vector<vector<bool>> on_path(r, vector<bool>(c));
    for (int i = 0; i < r; i++)
        visited[i][c - 1] = 1;
    for (int i = 0; i < c; i++)
        visited[0][i] = 1;
    visited[r - 1][c - 1] = 0;
    dfs(0, 0, visited, on_path);
    for (int i = 0; i < c; i++)
        visited[0][i] = 0;
    for (int i = 0; i < r; i++)
        visited[i][c - 1] = 0;
    dfs(0, 0, visited, on_path);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (on_path[i][j] || rand() % 100 >= probability)
            {
                cout << '.';
            }
            else
                cout << '#';
        }
        cout << endl;
    }
}
void block_corners() // type=5
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (((i == r - 2 and j == c - 1) || (i == r - 1 and j == c - 2)) and (i != 0 || j != 0))
                cout << '#';
            else
                cout << '.';
        }
        cout << endl;
    }
}
int main(int argc, char **argv)
{
    // The areguments should be: seed, type, mode, maxRC, probabilty
    // probabilty is used for type=4 and type=1, it should be a non-negative x integer<=100 which means that the probability of an obstacle is x percent
    // mode=0 -> r=1 , mode=1 c=1,  mode=2 -> r=c=sqrt(maxRC), mode=3 -> random r
    // type=1 -> random placement of obstacles with probabilty, type=2 -> couter heurstic , type=3 -> random placement of at most N obstacles,
    // type=4 -> generate two paths, type=5 -> empty with surrounded (r-1,c-1) or surrounded (0,0)
    rep(i, 0, argc) args.push_back(argv[i]);
    seed = convert_to_int(cmdlinearg("seed"));
    srand(seed);
    ll maxRC = convert_to_int(cmdlinearg("maxRC"));
    ll mode = convert_to_int(cmdlinearg("mode"));
    ll type = convert_to_int(cmdlinearg("type"));
    ld probability = stod(cmdlinearg("probability"));
    if (mode == 0)
    {
        r = 1;
        c = maxRC;
    }
    else if (mode == 1)
    {
        c = 1;
        r = maxRC;
    }
    else if (mode == 2)
    {
        r = c = sqrt(maxRC);
    }
    else if (mode == 3)
    {
        r = 1 + rand() % (ll)sqrt(maxRC);
        c = maxRC / r;
    }
    else
        assert(0);
    cout << r << " " << c << endl;
    if (type == 1)
    {
        random_with_probability(probability);
    }
    else if (type == 2)
    {
        counter_heuristic();
    }
    else if (type == 3)
    {
        ll n = maxRC / 10; // can be changed
        random_with_n(n, probability);
    }
    else if (type == 4)
    {
        generate_two_paths(probability);
    }
    else if (type == 5)
    {
        block_corners();
    }
    return 0;
}