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

  vi D = SpacedInts(n, 1, (int)Arg("maxd", MAXA));
  vi A = SpacedInts(n, 1, (int)Arg("maxa", MAXA));

  vector<pair<int,int>> DX;

  rep(c1,0,n){
      DX.push_back({D[c1]-A[c1], D[c1]});
  }

  bool same_d = (bool)Arg("same_d", 0);
  bool same_a = (bool)Arg("same_a", 0);
  
  sort(all(A));
  sort(all(D));
  sort(all(DX));
  if(same_a)assert(A[0] == A[n-1]);
  if(same_d)assert(D[0] == D[n-1]);
  rep(c1,0,n-1){
      assert(DX[c1].second <= DX[c1+1].second);
  }
}