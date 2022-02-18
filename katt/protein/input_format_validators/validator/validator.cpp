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

const int MAXN = 500000;
const int MAXK = 26;

void run() {
  int k = Int(1, Arg("maxk", MAXK));
  Space();
  int n = Int(1, Arg("maxn", MAXN));
  Endl();
  
  rep(c1,0,k){
    string s = Line();
    assert(sz(s) == k);
    rep(c2,0,k){
      assert(s[c2] == '0' || s[c2] == '1');
    }
  }

  string s = Line();
  assert(sz(s) == n);


}