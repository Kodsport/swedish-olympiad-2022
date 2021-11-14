#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b - 1); i >= (a); --i)
#define trav(a, x) for (auto &a : x)

#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl

#define umap unordered_map
#define uset unordered_set

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

const int INF = 1'000'000'007;

const int dir1[] = {1, 1, 1, 2, 2, 4};
const int dir2[] = {1, 2, 4, 2, 4, 4};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tc;
    int rows, cols;
    string goal[1001];
    cin >> tc >> rows >> cols;
    rep(i, 0, rows) cin >> goal[i];
    vi row[2], col[2];
    row[0].assign(cols, 1);
    row[1].assign(cols, 2);
    col[0].assign(rows, 4);
    col[1].assign(rows, 4);

    int best_score = 0;
    rep(i, 0, rows) rep(j, 0, cols) if (((col[0][i] | col[1][i] | row[0][j] | row[1][j]) == 7) == goal[i][j] - '0')++ best_score;

    bool cont = 1;
    int iters = 100;
    while (cont && iters--) {
        cont = 0;
        rep(j, 0, cols) {
            rep(k, 0, 6) {
                int cur_score = best_score;
                rep(i, 0, rows) {
                    if (((col[0][i] | col[1][i] | row[0][j] | row[1][j]) == 7) == goal[i][j] - '0') --cur_score;
                    if (((col[0][i] | col[1][i] | dir1[k] | dir2[k]) == 7) == goal[i][j] - '0') ++cur_score;
                }

                if (cur_score > best_score) {
                    cont = 1;
                    best_score = cur_score;
                    row[0][j] = dir1[k];
                    row[1][j] = dir2[k];
                }
            }
        }

        rep(i, 0, rows) {
            rep(k, 0, 6) {
                int cur_score = best_score;
                rep(j, 0, cols) {
                    if (((col[0][i] | col[1][i] | row[0][j] | row[1][j]) == 7) == goal[i][j] - '0') --cur_score;
                    if (((dir1[k] | dir2[k] | row[0][j] | row[1][j]) == 7) == goal[i][j] - '0') ++cur_score;
                }

                if (cur_score > best_score) {
                    cont = 1;
                    best_score = cur_score;
                    col[0][i] = dir1[k];
                    col[1][i] = dir2[k];
                }
            }
        }
    }

    rep(a, 0, 2) {
        rep(j, 0, cols) cout << (row[a][j] == 1 ? 'R' : row[a][j] == 2 ? 'G' : 'B');
        cout<<endl;
        rep(i, 0, rows) cout << (col[a][i] == 1 ? 'R' : col[a][i] == 2 ? 'G' : 'B');
        cout<<endl;
    }
    return 0;
}