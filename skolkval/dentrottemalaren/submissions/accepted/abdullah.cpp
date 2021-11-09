#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef int ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;
ll n;
bool done(vector<string> v)
{
    bool good = 1;
    rep(i, 0, n)
    {
        rep(j, 0, v[i].size()) good = good && (v[i][j] == '.' || v[i][j] == 'c');
    }
    return good;
}
void add_to_queue(queue<pair<ll, ll>> &q, vector<string> v)
{
    rep(i, 0, n)
    {
        set<char> s;
        rep(j, 0, n) if (v[i][j] != 'c') s.insert(v[i][j]);
        if (s.size() == 1 && *s.begin() != '.')
            q.emplace(i, 0);
        s.clear();
        rep(j, 0, n) if (v[j][i] != 'c') s.insert(v[j][i]);
        if (s.size() == 1 && *s.begin() != '.')
            q.emplace(i, 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<string> v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    vector<char> moves;
    vector<char> colors;
    while (!done(v))
    {
        queue<pair<ll, ll>> q;
        add_to_queue(q, v);
        while (!q.empty())
        {
            if (done(v))
                break;
            auto [x, y] = q.front();
            q.pop();
            if (y)
            {
                moves.push_back(char('A' + x));
                char cur_color = 'c';
                rep(i, 0, n)
                {
                    cur_color = v[i][x];
                    if (cur_color != 'c')
                        break;
                }
                colors.push_back(cur_color);
                rep(i, 0, n)
                {
                    v[i][x] = 'c';
                }
            }
            else
            {
                moves.push_back(char(x + '1'));
                char cur_color = 'c';
                rep(i, 0, n)
                {
                    cur_color = v[x][i];
                    if (cur_color != 'c')
                        break;
                }
                colors.push_back(cur_color);
                rep(i, 0, n)
                {
                    v[x][i] = 'c';
                }
            }
        }
    }
    reverse(all(moves));
    reverse(all(colors));
    trav(a, moves) cout << a;
    cout << endl;
    trav(a, colors) cout << a;
    cout << endl;
    return 0;
}
