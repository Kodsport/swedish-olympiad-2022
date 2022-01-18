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
  string mode = Arg("mode");
  int max_n = Arg("max_n");
  int n = Int(1, max_n);
  Space();
  int b = Int(0, 1000000000);
  Endl();
  vector<int> as = SpacedInts(n, 1, 1000);
  Eof();

  if(mode=="same_a"){
    assert(set<int>(as.begin(), as.end()).size()==1);
  }
}
