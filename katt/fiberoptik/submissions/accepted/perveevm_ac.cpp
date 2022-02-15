// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")
 
#include <stdio.h>
#include <bits/stdc++.h>
 
#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif
 
#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"
 
using ll = long long;
using ld = long double;
 
#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
 
template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 100100;
const int K = 110;
 
int n, k;
std::vector<std::pair<int, int>> g[N];
std::pair<int, ll> dp[2][N][K];
int need[N];
 
void dfs(int v) {
    int s = 0, t = 1;
    for (auto[to, cost] : g[v]) {
        dfs(to);
 
        for (int i = 0; i <= k; ++i) {
            dp[t][v][i] = std::make_pair(0, 0ll);
        }
 
        for (int i = 0; i <= k; ++i) {
            dp[t][v][i].first = dp[s][v][i].first + dp[need[to]][to][k].first;
            dp[t][v][i].second = dp[s][v][i].second + dp[need[to]][to][k].second;
 
            if (i == 0) {
                continue;
            }
 
            if (dp[t][v][i].first < dp[s][v][i - 1].first + dp[need[to]][to][k - 1].first + 1
                || (dp[t][v][i].first == dp[s][v][i - 1].first + dp[need[to]][to][k - 1].first + 1
                && dp[t][v][i].second > dp[s][v][i - 1].second + dp[need[to]][to][k - 1].second + cost)) {
                dp[t][v][i].first = dp[s][v][i - 1].first + dp[need[to]][to][k - 1].first + 1;
                dp[t][v][i].second = dp[s][v][i - 1].second + dp[need[to]][to][k - 1].second + cost;
            }
        }
 
        std::swap(s, t);
    }
 
    need[v] = s;
}
 
void run() {
    scanf("%d%d", &n, &k);
 
    for (int i = 1; i < n; ++i) {
        int p, w;
        scanf("%d%d", &p, &w);
        g[p - 1].push_back(std::make_pair(i, w));
    }
 
    dfs(0);
 
    printf("%d %lld\n", dp[need[0]][0][k].first, dp[need[0]][0][k].second);
}
 
int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);
 
    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();
 
    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif
 
    return 0;
}