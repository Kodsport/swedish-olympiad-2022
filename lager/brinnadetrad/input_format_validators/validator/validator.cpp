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
  int n = Int(1, Arg("maxn"));
  Endl();
  
  int MAXA = 1000000000;

  vi X = SpacedInts(n, 0, (int)Arg("maxx", MAXA));
  vi A = SpacedInts(n, 1, (int)Arg("maxa", MAXA));

  bool same_x = (bool)Arg("same_x", 0);
  bool same_a = (bool)Arg("same_a", 0);
  
  rep(c1,0,n-1){
    assert(X[c1] <= X[c1+1]);
  }

  sort(all(A));
  if(same_a)assert(A[0] == A[n-1]);
  if(same_x)assert(X[0] == X[n-1]);
 
}