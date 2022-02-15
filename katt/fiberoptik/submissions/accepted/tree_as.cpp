#define __GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<vector<pair<int, ll>>> ch;

vector<vector<vector<pair<int, ll>>>> dp;
vector<pair<int, ll>> minu;
vector<pair<int, ll>> minf;



int main() {
//    freopen("input", "r", stdin);
    cin >> n >> k;
    ch.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        ll w;
        cin >> p >> w;
        p--;
        ch[p].push_back({i, w});
    }

    // dp[i][j][p] -- vertex i, first j children considered, p edges used {mincomp, mincost}
    // minu[i] -- {mincomp in i subtree no edge up, mincost to get}
    // minf[i] -- {mincomp in i subtree with edge up, mincost to get}
    dp.resize(n);
    minu.resize(n);
    minf.resize(n);
    for (int i = n - 1; i >= 0; i--) {
        int chn = ch[i].size();
        dp[i].resize(chn + 1);
        dp[i][0].resize(1); 
        dp[i][0][0] = {1, 0};
        for (int j = 0; j < ch[i].size(); j++) {
            int chi = ch[i][j].first;
            dp[i][j + 1].resize(min(k + 1, (int) dp[i][j].size() + 1));
            for (int p = 0; p < dp[i][j].size(); p++) {
                // do not take edge to j
                int comp = dp[i][j][p].first + minu[chi].first;
                ll cost = dp[i][j][p].second + minu[chi].second;
                auto np = make_pair(comp, cost);
//                assert(dp[i][j + 1][p].first != 0 || p == 0);
                if (dp[i][j + 1][p].first == 0 || np < dp[i][j + 1][p]) {
                    dp[i][j + 1][p] = np;
                }
                if (p < k) {
//                    assert(dp[i][j + 1][p + 1].first == 0);
                    // take edge to j
                    comp = dp[i][j][p].first + minf[chi].first - 1;
                    cost = dp[i][j][p].second + minf[chi].second + ch[i][j].second;
                    dp[i][j + 1][p + 1] = {comp, cost};
                }
            }
        }
        minf[i] = {n + 1, 0};
        for (int p = 0; p < k && p < dp[i][chn].size(); p++) {
            if (dp[i][chn][p].first != 0) {
                if (dp[i][chn][p] < minf[i]) {
                    minf[i] = dp[i][chn][p];
                }
            }
        }
        minu[i] = minf[i];
        if (dp[i][chn].size() > k && dp[i][chn][k] < minu[i]) {
//            assert(dp[i][chn].size() == k + 1);
            minu[i] = dp[i][chn][k];
        }
    }

    cout << (n - minu[0].first) << " " << minu[0].second << endl;

    return 0;
}
