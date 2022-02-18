
// formally this is O(n^3), but it's very likely impossible to fail with n <= 2000


/**
 *    author:  tourist
 *    created: 04.04.2021 19:24:54       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  vector<string> g(k);
  for (int i = 0; i < k; i++) {
    cin >> g[i];
  }
  string foo;
  cin >> foo;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    s[i] = (int) (foo[i] - 'a');
  }
  vector<int> r(n, n - 1);
  vector<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && g[s[st.back()]][s[i]] == '0') {
      r[st.back()] = i - 1;
      st.pop_back();
    }
    st.push_back(i);
  }
  vector<string> best(n);
  for (int i = n - 1; i >= 0; i--) {
    if (r[i] == n - 1) {
      best[i] += foo[i];
    } else {
      best[i] = "{";
      for (int j = i + 1; j <= r[i] + 1; j++) {
        best[i] = min(best[i], best[j]);
      }
      best[i] = foo[i] + best[i];
    }
  }
  cout << best[0] << '\n';
  return 0;
}
