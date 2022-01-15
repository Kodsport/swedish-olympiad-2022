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
  set<int> as;
  for (int i = 0; i < n; i++)
  {
    int a = Int(1, 1000);
    as.insert(a);
    if (i + 1 != n)
      Space();
  }
  Endl();
  Eof();

  if(mode=="same_a"){
    assert(as.size()==1);
  }
}
