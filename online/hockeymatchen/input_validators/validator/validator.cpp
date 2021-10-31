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


void run() {
  int max_value = Arg("max_value");
  bool doable=Arg("doable",0);
  vector<int> v(6);
  rep(i,0,3){
    v[i]=Int(-1,max_value);
    if(i!=2)Space();
  }
  Endl();
  rep(i,3,6){
    v[i]=Int(-1,max_value);
    if(i!=5)Space();
  }
  Endl();
  if(doable){
    ll howmany=(v[0]!=-1)+(v[4]!=-1)+(v[5]!=-1);
    assert(howmany>= 2 || (v[5]==0));
    howmany=(v[1]!=-1)+(v[2]!=-1)+(v[3]!=-1);
    assert(howmany>= 2 || (v[2]==0));
  }
  auto leq = [&](int x, int y){ return (v[x] == -1 || v[y] == -1 || v[x] <= v[y]); };
  assert(leq(0,5) && leq(4,5));
  assert(leq(1,2) && leq(3,2));
  if(v[0]!=-1 && v[4]!=-1 && v[5]!=-1)assert(v[0]+v[4]==v[5]);
  if(v[1]!=-1 && v[2]!=-1 && v[3]!=-1)assert(v[1]+v[3]==v[2]);
  Eof();
}

