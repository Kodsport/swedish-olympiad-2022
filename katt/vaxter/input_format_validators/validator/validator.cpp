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

const int MAXN = 200000;
const int MAXV = 1000000000;

void run()
{
  int max_n = Arg("max_n", MAXN);
  int max_q = Arg("max_q", MAXN);
  int max_value = Arg("max_value",MAXV);
  bool unique = Arg("unique", 0);
  
  int n = Int(1, max_n);
  Space();
  int q = Int(1, max_q);
  Endl();

  vi v = SpacedInts(n, 0, max_value);
  set<int> seen;
  for(int i = 0; i < n; i++){
    if(unique)assert(seen.find(v[i]) == seen.end());
    seen.insert(v[i]);
  }

  for (int i = 0; i < q; i++){
    Int(0, max_value);
    Endl();
  }
  Eof();
}
