//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

// #define FAST_RANDOM

// #ifndef FAST_RANDOM
// #ifdef GOLIKOV
// mt19937_64 rng(566);
// #else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// #endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  using arr_t = array<pair<int, ll>, 101>;

  int n, k;
  cin >> n >> k;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 1; i < n; ++i) {
    int par, wei;
    cin >> par >> wei;
    wei = -wei;
    --par;
    graph[par].emplace_back(i, wei);
  }

  pair<int, ll> INF{int(-1e8), int(-1e8)};

  vector<arr_t> cur(n), nw(n);

  auto dfs = [&](auto&& self, int v) -> pair<pair<int, ll>, pair<int, ll>> {
    int sz = 0;
    cur[v][0] = make_pair(0, 0);

    for (auto[u, w] : graph[v]) {
      auto resu = self(self, u);
      int nsz = min(sz + 1, k);
      for (int i = 0; i <= nsz; ++i) {
        nw[v][i] = INF;
      }
      int realnsz = 0;
      for (int i = 0; i <= sz; ++i) {
        for (int t : {0, 1}) {
          {
            if (i + t > k || resu.first == INF || cur[v][i] == INF) {
              continue;
            }
            smax(realnsz, i + t);
            smax(nw[v][i + t], make_pair(resu.first.first + t + cur[v][i].first, resu.first.second + t * w + cur[v][i].second));
          }
          if (t == 1) {
            continue;
          }

          smax(realnsz, i + t);
          smax(nw[v][i + t], make_pair(resu.second.first + t + cur[v][i].first, resu.second.second + t * w + cur[v][i].second));
        }
      }
      cur[v] = nw[v];
      sz = realnsz;
    }

    auto small = INF;
    for (int i = 0; i <= sz && i < k; ++i) {
      smax(small, cur[v][i]);
    }
    return make_pair(small, sz == k ? cur[v][k] : INF);
  };
  auto[x, y] = dfs(dfs, 0);
  auto ans = max(x, y);
  cout << ans.first << ' ' << -ans.second << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}
