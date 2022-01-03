#include "jngen.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void gen_odd_cactus(int n) {
  // TODO: implement
};


struct UF { // to check bipartiteness
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

int main(int argc, char *argv[]) {
  registerGen(argc, argv);
  parseArgs(argc, argv);

  int n, q;
  string type;
  getNamed(n,q,type);
  int m = getOpt("m",-1);

  Graph g;
  if(type == "empty") {
    assert(m == -1);
    g = Graph::empty(n);
  }
  else if(type == "complete") {
    assert(m == -1);
    g = Graph::complete(n);
  }
  else if(type == "cycle") {
    assert(m == -1);
    g = Graph::cycle(n);
  }
  else if(type == "wheel") {
    assert(m == -1);
    g = Graph::cycle(n-1);
    g.setN(n);
    int gap = getOpt("gap",1);
    for(int i = 0; i < n-1; i += gap) g.addEdge(i,n-1);
  }
  else if(type == "wheel2") {
    assert(m == -1);
    g = Graph::cycle(n);
    int gap = getOpt("gap",1);
    for(int i = 0; i < n-n/2; i += gap) g.addEdge(i,i+n/2);
  }
  else if(type == "random") {
    g = Graph::random(n,m);
  }
  else if(type == "bipartite") {
    int left = getOpt("left",n/2);
    g = Graph::randomBipartite(left, n-left, m);
  }
  else if(type == "caterpillar") { // a tree
    g = Tree::caterpillar(n,n/2);
  }
  else if(type == "star") { // a tree
    g = Tree::star(n);
  }
  else if(type == "binary") { // a tree
    g = Tree::binary(n);
  }
  else if(type == "bamboo") { // a tree
    g = Tree::bamboo(n);
  }
  //else if(type == "cactus") { // odd cactus
  //  g = gen_cactus();
  //}
  else assert(false);

  assert(g.n() == n);

  int force_deg3 = getOpt("forced_deg3",0);
  int bip = getOpt("bipartite",0);
  int extra_random_edges = getOpt("extra_random_edges",0);

  UF uf(2*n);
  set<pii> edges;
  for(auto [a,b] : g.edges()) {
    edges.emplace(a,b);
    edges.emplace(b,a);
    uf.join(a,b+n);
    uf.join(a+n,b);
  }

  if(force_deg3) {
    while(true) {
      vi need;
      rep(i,0,n) if(sz(g.edges(i)) < 3) need.emplace_back(i);
      if(sz(need) == 0) break;

      rep(i,0,3) need.emplace_back(rnd.next(n));
      for(int i = sz(need); i--;) swap(need[i], need[rnd.next(i+1)]);
      if(sz(need) % 2 != 0) need.emplace_back(rnd.next(n));

      rep(i,0,sz(need)/2) {
        int a = need[2*i], b = need[2*i+1];
        if(a == b) continue;
        if(edges.count(pii(a,b))) continue;
        g.addEdge(a,b);
        edges.emplace(a,b);
        edges.emplace(b,a);
        uf.join(a,b+n);
        uf.join(a+n,b);
      }
    }
    rep(i,0,n) assert(sz(g.edges(i)) >= 3);
  }

  rep(i,0,extra_random_edges) {
    int a = rnd.next(n);
    int b = a;
    if(bip) {
      while(b == a || uf.sameSet(a,b)) b = rnd.next(n);
    }
    else {
      while(b == a) b = rnd.next(n);
    }
    if(edges.count(pii(a,b))) continue;
    g.addEdge(a,b);
    edges.emplace(a,b);
    edges.emplace(b,a);
    uf.join(a,b+n);
    uf.join(a+n,b);
  }


  g.shuffle();

  cout << g.printN().printM().add1() << endl;
}
