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



struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

void run() {
  int maxn = Arg("maxn");
  int maxm = Arg("maxm");

  int mindeg = Arg("mindeg",0);
  int maxdeg = Arg("maxdeg",maxn);

  int bipartite = Arg("bipartite",0);

  int n = Int(1,maxn);
  Space();
  int m = Int(0,maxm);
  Endl();

  set<pii> s;

  vi deg(n);
  UF uf(2*n);

  rep(i,0,m) {
    int a = Int(1,n); Space();
    int b = Int(1,n); Endl();
    --a,--b;
    if(s.count(pii(a,b))) die_line("duplicate edge");
    if(a == b) die_line("self_loop");
    uf.join(a,b+n);
    uf.join(a+n,b);
    s.emplace(a,b);
    s.emplace(b,a);
    ++deg[a];
    ++deg[b];
  }
  Eof();

  rep(x,0,n) {
    if(deg[x] < mindeg || deg[x] > maxdeg) die_line("degrees are bad");
    if(bipartite && uf.sameSet(x,x+n)) die_line("not bipartite");
  }
}

