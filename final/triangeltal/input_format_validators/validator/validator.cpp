#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void run() {
  int n = Int(3, Arg("maxn"));
  Endl();

  vector<int> as = SpacedInts(n, 1, (int)Arg("maxa", n));
  if (Arg("same", 0)) {
    rep(i,0,n) {
      assert(as[i] == as[0]);
    }
  }
}
