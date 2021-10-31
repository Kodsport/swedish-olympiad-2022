#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

void run() {
  int n = Int(1,10);
  Endl();
  string ok_chars = ".,?!_";
  rep(i,0,n) {
    string s = _token();
    if(sz(s) == 0) die_line("empty word");
    for(char c:s)
      if(!(isalpha(c) || count(all(ok_chars),c)))
        die_line("invalid char in word \"" + s +"\"");
    if(i == n-1) Endl();
    else Space();
  }
  Eof();
}
