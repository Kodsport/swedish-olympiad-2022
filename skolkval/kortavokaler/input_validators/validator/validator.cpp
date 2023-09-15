#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

void run() {
  bool alleq = Arg("eq", false);
  int maxlen = Arg("maxlen", 50);
	string S = Line();
  assert(sz(S) <= maxlen);
  if (alleq) {
    rep(i,0,sz(S) - 1) assert(S[i] == S[i + 1]);
  }
}
