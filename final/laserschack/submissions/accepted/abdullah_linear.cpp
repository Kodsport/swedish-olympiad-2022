#include <bits/stdc++.h>

typedef long long ll;
const long long inf = 2e9;
using namespace std;

struct UF
{
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b)
	{
		a = find(a), b = find(b);
		if (a == b)
			return false;
		if (e[a] > e[b])
			swap(a, b);
		e[a] += e[b];
		e[b] = a;
		return true;
	}
};
ll r, c;
ll get_node(ll i, ll j)
{
	return i * c + j;
}
ll inside(ll i, ll j)
{
	return i >= 0 and j >= 0 and i < r and j < c;
}
vector<ll> change_x = {0, 0, -1, 1};
vector<ll> change_y = {1, -1, 0, 0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	ll attack, king;
	vector<vector<ll>> dist(r, vector<ll>(c, -1));
	vector<vector<pair<ll, ll>>> nodes_at(r + c + 1);
	vector<vector<bool>> is_mirror(r, vector<bool>(c));
	queue<pair<ll, ll>> q;
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			if (s[j] == 'A')
				attack = get_node(i, j);
			if (s[j] == 'K')
				king = get_node(i, j);
			if (s[j] == 'R')
			{
				dist[i][j] = 0;
				q.push(make_pair(i, j));
			}
			if (s[j] == 'o' || s[j] == 'A' || s[j] == 'K')
				is_mirror[i][j] = 1;
		}
	}
	while (!q.empty())
	{
		pair<ll, ll> cur = q.front();
		q.pop();
		nodes_at[dist[cur.first][cur.second]].push_back(cur);

		for (int i = 0; i < 4; i++)
		{
			int x = cur.second + change_x[i];
			int y = cur.first + change_y[i];
			if (inside(y, x) and dist[y][x] == -1)
			{
				q.push(make_pair(y, x));
				dist[y][x] = dist[cur.first][cur.second] + 1;
			}
		}
	}
	// Create two nodes for each square, one that connects with horizontal neighbors and one that connect with vertical ones and connect the two nodes in a case of a mirror
	UF uf(2 * r * c);
	vector<vector<bool>> turned_on(r, vector<bool>(c));
	for (int i = r + c; i >= 0; i--)
	{
		for (auto &cur : nodes_at[i])
		{
			if (is_mirror[cur.first][cur.second])
				uf.join(get_node(cur.first, cur.second), get_node(cur.first, cur.second) + r * c);
			turned_on[cur.first][cur.second] = 1;
			for (int j = 0; j < 4; j++)
			{
				int x = cur.second + change_x[j];
				int y = cur.first + change_y[j];
				if (inside(y, x) and turned_on[y][x])
					uf.join(get_node(y, x) + r * c * (j < 2), get_node(cur.first, cur.second) + r * c * (j < 2));
			}
		}
		if (uf.sameSet(attack, king))
		{
			cout << i << endl;
			return 0;
		}
	}
	return 1;
}
