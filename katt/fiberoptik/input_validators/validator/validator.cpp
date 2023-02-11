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

const int MAXN = 100000;
const int MAXK = 100;
const int MAXW = 1000000000;

void run() {
  int n = Int(2, Arg("maxn", MAXN));
  Space();
  int k = Int(1, Arg("maxk", MAXK));
  Endl();
  int maxw = Arg("maxw", MAXW);
  
  rep(c1,0,n-1){
    int p = Int(1, n);
    Space();
    int w = Int(0, maxw);
    Endl();
  }
}