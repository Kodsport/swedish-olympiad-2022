#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(i, a) for (auto &i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void run()
{
  int maxRC = Arg("maxRC");
  bool empty = Arg("empty");
  int r = Int(1, maxRC);
  Space();
  int c = Int(1, maxRC);
  Endl();
  assert(r * c <= maxRC);
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      char c = Char();
      assert(c == '.' || c == '#');
      if (empty)
        assert(c == '.');
      if((i==0 and j==0) || (i==r-1 and j==c-1) )assert(c=='.');
    }
    Endl();
  }
}
