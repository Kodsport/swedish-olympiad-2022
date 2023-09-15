#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

void run() {
	int n = Int(1, Arg("maxn", 9)); 
  Endl();
  int dots = 0;
  rep(i,0,n) {
    string s = Line();
    assert(s.size() == n);
    rep(j,0,n){
      dots += (s[j] == '.');
    }
    for (char c : s) assert(c == 'V' || c == 'S' || c == '.');
  }
  assert(dots != n*n);
}
