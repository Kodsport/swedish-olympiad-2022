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
  int maxn = Arg("maxn");
  int k = 3;
  int same = Arg("same", 0);

  int n = Int(3, maxn);
  int maxa = Arg("maxa", n);
  Endl();

  int a0;
  rep(c1,0,n){
      int a = Int(1, maxa);

        if(c1 == 0){
            a0 = a;
        }
        else{
            if(same == 1)assert(a == a0);
        }

      if(c1 < n-1)Space();
  }
  Endl();
  Eof();

}

