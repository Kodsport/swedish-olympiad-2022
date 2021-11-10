#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(it,x) for(auto& it : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S> &v) { return os << v.first << " " << v.second; }
template<typename T, typename S> istream& operator>>(istream& is, const pair<T, S> &v) { return is >> v.first >> v.second; }
template<typename T> ostream& operator<<(ostream& os, const vector<T> &v) { rep(i,0,sz(v)) { if (i) os << " " << v[i]; else os << v[i]; } os << endl; return os; }
template<typename T> istream& operator>>(istream& is, vector<T> &v) { trav(it, v) is >> it; return is; }
template<typename T> using v = vector<T>; template<typename T> using vv = v<v<T>>; template<typename T> using vvv = v<v<v<T>>>;
template<typename T> std::vector<T> make(T init, std::size_t size) { return std::vector<T>(size, init); }
template<typename T, typename... Args> auto make(T init, std::size_t first, Args... sizes) { auto inner = make<T>(init, sizes...); return std::vector<decltype(inner)>(first, inner); }
template<typename A, typename B> auto smax(A& a, const B& b) { if (b > a) a = b; }
template<typename A, typename B> auto smin(A& a, const B& b) { if (b < a) a = b;}
bool within(int r, int c, int R, int C) { return 0 <= r && r < R && 0 <= c && c < C; }

struct Node {
  Node *l = 0, *r = 0;
  int lo, hi, val = 0;
  Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
  int query(int L, int R) {
    if (R <= lo || hi <= L) return 0;
    if (L <= lo && hi <= R) return val;
    push();
    return l->query(L, R) + r->query(L, R);
  }
  void inc(int pos) {
    if (pos + 1 <= lo || hi <= pos) return;
    if (pos <= lo && hi <= pos+1) {
      val++;
    } else {
      push(), l->inc(pos), r->inc(pos);
      val = l->val + r->val;
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo)/2;
      l = new Node(lo, mid); r = new Node(mid, hi);
    }
  }
};

struct Q {
  int a, b;
  int name;
};

void solve() {
  int N;
  cin >> N;
  map<int, int> evs;

  unordered_map<int, vi> R;
  rep(i,0,N) {
    int l, r;
    cin >> l >> r;
    assert(l <= r);
    R[r].push_back(l);
    evs[r];
    evs[l]++;
  }

  int queries;
  cin >> queries;
  unordered_map<int, vector<Q>> qs;
  rep(i,0,queries) {
    Q query;
    cin >> query.a >> query.b;
    if (query.a > query.b) swap(query.a, query.b);
    query.name = i;
    qs[query.b].push_back(query);
    evs[query.a];
    evs[query.b];
  }

  const int mx = 1'000'000'000 + 1;
  Node t(0, mx);

  int endpoints = 0;
  vi ans(queries);
  trav(ev, evs) {
    int p = ev.first;
    ev.second += endpoints;
    endpoints = ev.second;
    trav(it, qs[p]) {
      int epsbetween = endpoints - evs[it.a];
      ans[it.name] = epsbetween - 2 * t.query(it.a + 1, mx);
    }
    trav(it, R[p]) t.inc(it);
    endpoints += sz(R[p]);
  }
  trav(it, ans) cout << it << endl;
  _Exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int TC = 1;
  if (!TC) cin >> TC;
  rep(i,1,TC+1) {
    // cout << i << " ";
    solve();
  }
}

