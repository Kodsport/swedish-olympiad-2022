#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

void run() {
	int n = Int(1, 12); Endl();
  rep(i,0,n) {
    string s = Line();
    for (char c : s) assert(c == 'V' || c == 'S' || c == '.');
  }
}
