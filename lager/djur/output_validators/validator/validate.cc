#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;
vector<ll> change_r = {1, -1, 0, 0};
vector<ll> change_c = {0, 0, 1, -1};
bool inside(ll i, ll j, ll r, ll c)
{
    return i >= 0 and j >= 0 and i < r and j < c;
}
bool bfs(vector<string> &ans, char color)
{
    queue<pair<ll, ll>> q;
    ll r = ans.size();
    ll c = ans[0].size();
    vector<vector<bool>> visited(r, vector<bool>(c));
    visited[0][0] = 1;
    q.emplace(0, 0);
    while (!q.empty())
    {
        pair<ll, ll> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ll next_r = cur.first + change_r[i];
            ll next_c = cur.second + change_c[i];
            if (inside(next_r, next_c, r, c) and !visited[next_r][next_c] and (ans[next_r][next_c] == color || (next_r == r - 1 and next_c == c - 1)))
            {
                visited[next_r][next_c] = 1;
                q.emplace(next_r, next_c);
            }
        }
    }
    if (!visited[r - 1][c - 1])
        return 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (ans[i][j] == color and !visited[i][j])
                return 0;
    return 1;
}
int main(int argc, char **argv)
{
    init_io(argc, argv);

    int r, c;
    judge_in >> r >> c;

    vector<string> net(r);
    rep(c1, 0, r)
    {
        judge_in >> net[c1];
    }

    auto check = [&](istream &sol, feedback_function feedback)
    {
        string res;
        if (!(sol >> res))
            feedback("Expected more output");
        for (char &c : res)
            c = (char)toupper(c);
        if (res != "NO" && res != "YES")
            feedback("Answer \'%s\' is not {YES|NO}", res.c_str());

        if (res == "NO")
        {
            string trailing;
            if (sol >> trailing)
                feedback("Trailing output");
            return false;
        }
        vector<string> ans;
        vector<char> valid_characters = {'.', '#', 'K', 'V'};
        for (int i = 0; i < r; i++)
        {
            string cur_row;
            if (!(sol >> cur_row))
            {
                feedback("Expected more output");
            }
            if (sz(cur_row) != c)
                feedback("Length of the row %d was %d instead of %d", i, sz(cur_row), c);
            ans.push_back(cur_row);
            for (int j = 0; j < c; j++)
            {
                if (find(valid_characters.begin(), valid_characters.end(), cur_row[j]) == valid_characters.end())
                    feedback("Output contained invalid character");
                if (net[i][j] == '#' and cur_row[j] != '#')
                    feedback("Changed an obstacle");
                if (((i == 0 and j == 0) || (i == r - 1 and j == c - 1)) and cur_row[j] != '.')
                    feedback("Changed starting points");
            }
        }
        if (!bfs(ans, 'K'))
            feedback("Path of K is not connected or it doesn't connectes the starting position and the ending position");
        if (!bfs(ans, 'V'))
            feedback("Path of V is not connected or it doesn't connectes the starting position and the ending position");
        string trailing;
        if (sol >> trailing)
            feedback("Trailing output");
        return true;
    };

    bool judge_found = check(judge_ans, judge_error);
    bool author_found = check(author_out, wrong_answer);

    if (!judge_found && author_found)
        judge_error("Judge said no, but contestant found a solution");

    if (judge_found && !author_found)
        wrong_answer("Contestant said no, but judge found a solution");

    accept();
}