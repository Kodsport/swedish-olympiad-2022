#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) // ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

void run()
{
  int max_n = Arg("max_n");
  int plus_one = Arg("plus_one");
  int max_value = Arg("max_value");
  int n = Int(1, max_n);
  Space();
  int m = Int(n, n + plus_one);
  Endl();
  rep(i, 0, n)
  {
    int cur = Int(0, max_value);
    if (i + 1 != n)
      Space();
  }
  Endl();
  rep(i, 0, m)
  {
    int cur = Int(0, max_value);
    if (i + 1 != m)
      Space();
  }
  Endl();
  Eof();
}
