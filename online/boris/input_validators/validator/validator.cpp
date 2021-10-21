#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int large = 1'000'000;

void run() {
  int max_n = Arg("max_n");
  int max_xy = Arg("max_xy");
  int max_s = Arg("max_s");
  int max_t = Arg("max_t");

  set<tuple<int,int,int>> seen;

  int n = Int(1, max_n);
  Endl();
  rep(i,0,n) {
    int t = Int(0, max_t); // t_i
    Space();
    int s = Int(1, max_s); // s_i
    Space();
    int x = Int(0, max_xy); // x_i
    Space();
    int y = Int(0, max_xy); // y_i
    Endl();

    if(seen.count({t,x,y})) die_line("duplicate (t,x,y)");
    seen.emplace(t,x,y);
  }

  Eof();
}

