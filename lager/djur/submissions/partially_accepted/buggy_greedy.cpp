#include <bits/stdc++.h>

typedef long long ll;
const long long inf = 2e9;
using namespace std;

bool swapped=0;
ll r, c;
bool inside(ll x, ll y)
{
    return x >= 0 and y >= 0 and x < c and y < r;
}
bool dfs(vector<string> &v, ll cur_x, ll cur_y, char color, vector<vector<bool>> &visited,vector<ll> change_x, vector<ll> change_y)
{
    if(cur_y==r-1){
        change_x={0,1,0,-1};
        change_y={1,0,-1,0};
    }
    if (cur_x == c - 1 and cur_y == r - 1)
        return 1;
    visited[cur_y][cur_x] = 1;
    for (int i = 0; i < 4; i++)
    {
        ll x = cur_x + change_x[i];
        ll y = cur_y + change_y[i];
        if (inside(x, y) and v[y][x] == '.' and !visited[y][x])
        {
            if (dfs(v, x, y, color, visited,change_x,change_y))
            {
                v[cur_y][cur_x] = color;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c;
    vector<string> v(r);
    for (int i = 0; i < r; i++)
        cin >> v[i];
    vector<vector<bool>> visited(r, vector<bool>(c));
    vector<ll> change_x={-1,0,1,0};
    vector<ll> change_y={0,1,0,-1};
    dfs(v, 0, 0, 'K', visited,change_x,change_y);
    v[0][0] = v[r - 1][c - 1] = '.';
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (v[i][j] != 'K')
                visited[i][j] = 0;
    if (!dfs(v, 0, 0, 'V', visited,change_x,change_y)){
        cout << "NO\n";
    }
    else
    {
        v[0][0] = v[r - 1][c - 1] = '.';
        cout << "YES" << '\n';
        for (int i = 0; i < r; i++)
            cout << v[i] << '\n';
    }
    return 0;
}
