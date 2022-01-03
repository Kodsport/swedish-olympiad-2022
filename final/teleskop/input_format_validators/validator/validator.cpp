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
  int max_k = Arg("max_k");
  int n = Int(1, max_n);
  Space();
  int k = Int(0, max_k);
  Endl();
  for (int i = 0; i < n; i++)
  {
    int a = Int(0, 359);
    if (i + 1 != n)
      Space();
  }
  Endl();
  Eof();
}
