#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(i, a) for (auto &i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<ll> change_x = {-1, 0, 1, 0}; // Here the order matters
vector<ll> change_y = {0, 1, 0, -1};
int r, c;
bool inside(ll x, ll y)
{
  return x >= 0 and y >= 0 and x < c and y < r;
}
bool dfs(vector<string> &v, ll cur_x, ll cur_y, char color, vector<vector<bool>> &visited)
{
  if (cur_x == c - 1 and cur_y == r - 1)
    return 1;
  visited[cur_y][cur_x] = 1;
  for (int i = 0; i < 4; i++)
  {
    ll x = cur_x + change_x[i];
    ll y = cur_y + change_y[i];
    if (inside(x, y) and v[y][x] == '.' and !visited[y][x])
    {
      if (dfs(v, x, y, color, visited))
      {
        v[cur_y][cur_x] = color;
        return 1;
      }
    }
  }
  return 0;
}
void run()
{
  int maxRC = Arg("maxRC");
  bool empty = Arg("empty", 0);
  bool two_ways = Arg("two_ways", 0);
  bool three = Arg("three", 0);
  r = Int(1, maxRC);
  if (three)
    assert(r == 3);
  Space();
  c = Int(1, maxRC);
  Endl();
  assert(r * c <= maxRC);
  assert(r * c > 1);
  vector<string> v;
  for (int i = 0; i < r; i++)
  {
    string cur_row = "";
    for (int j = 0; j < c; j++)
    {
      char chr = Char();
      cur_row += chr;
      assert(chr == '.' || chr == '#');
      if (empty)
        assert(chr == '.');
      if ((i == 0 and j == 0) || (i == r - 1 and j == c - 1))
        assert(chr == '.');
    }
    v.push_back(cur_row);
    Endl();
  }
  if (two_ways)
  {
    vector<vector<bool>> visited(r, vector<bool>(c));
    assert(dfs(v, 0, 0, 'K', visited) and dfs(v, 0, 0, 'V', visited));
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if ((i != 0 || j != 0) and (i != r - 1 || j != c - 1))
          assert(v[i][j] != '.');
      }
    }
  }
}
