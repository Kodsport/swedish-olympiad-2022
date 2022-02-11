#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)
#define endl '\n'
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
            if (rand() % 100 < probability and (i != 0 || j != 0) and (i != r - 1 || j != c - 1))
                cout << '#';
            else
                cout << '.';
        cout << endl;
    }
}
void counter_heuristic() // type=2
{
    if (r == 3)
    {
        for (int i = 0; i < c; i++)
            cout << '.';
        cout << endl;
        for (int i = 0; i < c - 1; i++)
            cout << (i % 2 ? '#' : '.');
        cout << '.';
        cout << endl;
        for (int i = 0; i < c; i++)
            cout << '.';
        cout << endl;
        return;
    }
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
    random_shuffle(change2.begin(), change2.end());
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
bool bfs(ll start_r, ll start_c, vector<vector<bool>> &visited, vector<vector<bool>> &on_path)
{
    queue<pair<ll, ll>> q;
    q.emplace(start_r, start_c);
    visited[start_r][start_c] = 1;
    vector<vector<pair<ll, ll>>> path(r, vector<pair<ll, ll>>(c, make_pair(-1, -1)));
    while (!q.empty())
    {
        pair<ll, ll> cur = q.front();
        q.pop();
        random_shuffle(change.begin(), change.end());
        for (int i = 0; i < 4; i++)
        {
            ll next_r = cur.first + change[i].first;
            ll next_c = cur.second + change[i].second;
            if (inside(next_r, next_c) and !visited[next_r][next_c])
            {
                visited[next_r][next_c] = 1;
                q.emplace(next_r, next_c);
                path[next_r][next_c] = cur;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            visited[i][j] = 0;
    }
    pair<ll, ll> cur = make_pair(r - 1, c - 1);
    while (cur.first != -1)
    {
        on_path[cur.first][cur.second] = visited[cur.first][cur.second] = 1;
        cur = path[cur.first][cur.second];
    }
    return 1; // doesn't matter. The function had to be bool type so that it could be used as an argument
}
void generate_two_paths(ll probability, bool (*f)(ll, ll, vector<vector<bool>> &, vector<vector<bool>> &)) // type=4
{
    vector<vector<bool>> visited(r, vector<bool>(c));
    vector<vector<bool>> on_path(r, vector<bool>(c));
    for (int i = 0; i < r; i++)
        visited[i][c - 1] = 1;
    for (int i = 0; i < c; i++)
        visited[0][i] = 1;
    visited[r - 1][c - 1] = 0;
    f(0, 0, visited, on_path);
    for (int i = 0; i < c; i++)
        visited[0][i] = 0;
    for (int i = 0; i < r; i++)
        visited[i][c - 1] = 0;
    f(0, 0, visited, on_path);
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

int main(int argc, char **argv)
{
    // The areguments should be: seed, type, mode, maxRC, probabilty
    // probabilty is used for type=4 and type=1, it should be a non-negative x integer<=100 which means that the probability of an obstacle is x percent
    // mode=1 -> r=1 ,  mode=2 -> r=c=sqrt(maxRC), mode=3 -> r=3 , mode=4 -> random r
    // type=1 -> random placement of obstacles with probabilty, type=2 -> couter heurstic
    // type=3 -> generate two paths, type=4 -> thre is only two paths
    rep(i, 0, argc) args.push_back(argv[i]);
    seed = convert_to_int(cmdlinearg("seed"));
    srand(seed);
    ll maxRC = convert_to_int(cmdlinearg("maxRC"));
    ll mode = convert_to_int(cmdlinearg("mode"));
    ll type = convert_to_int(cmdlinearg("type"));
    ll probability = stod(cmdlinearg("probability"));
    if (mode == 1)
    {
        r = 1;
        c = maxRC;
    }
    else if (mode == 2)
    {
        r = c = sqrt(maxRC);
    }
    else if (mode == 3)
    {
        assert(maxRC >= 3);
        r = 3;
        c = maxRC / 3;
    }
    else if (mode == 4)
    {
        if (type == 2)
        {
            ll RC = maxRC;
            assert(RC >= 10);
            c = 5;
            r = RC / 5;
        }
        else
        {
            r = 1 + rand() % (ll)(sqrt(maxRC));
            if (type >= 3 and r == 1)
                r++;
            c = maxRC / r;
        }
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
        assert(r > 1 and c > 1);
        generate_two_paths(probability, bfs);
    }
    else if (type == 4)
    {
        assert(r > 1 and c > 1);
        generate_two_paths(probability, dfs);
    }
    else
        assert(0);
    return 0;
}