#include "validate.h"

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

int main(int argc, char **argv) {
  init_io(argc, argv);

  int n, m;
  judge_in >> n >> m;

  set<pii> edges;
  rep(i,0,m) {
    int a, b;
    judge_in >> a >> b;
    edges.emplace(a,b);
    edges.emplace(b,a);
  }

  auto check = [&](istream& sol, feedback_function feedback){
    string ans;
    if(!(sol >> ans)) feedback("Expected more output");
    for (char& c : ans) c = (char)toupper(c);
    if(ans != "NO" && ans != "YES")
      feedback("Answer \'%s\' is not {YES|NO}", ans.c_str());

    if(ans == "NO") {
      string trailing;
      if(sol >> trailing) feedback("Trailing output");
      return false;
    }

    int k;
    if(!(sol >> k)) feedback("Expected more output");
    if(k < 4 || k > n) feedback("k = %d is out of range", k);
    if(k % 2 != 0) feedback("k = %d is odd", k);

    vi seen(n+1,0);
    vi c;
    rep(i,0,k) {
      int x;
      if(!(sol >> x)) feedback("Expected more output");
      if(x < 1 || x > n) feedback("vertex x = %d is out of range", x);
      if(seen[x]) feedback("duplicate vertex x = %d", x);
      c.emplace_back(x);
      seen[x] = 1;
    }

    rep(i,0,k) if(!edges.count(pii(c[i], c[(i+1)%k])))
      feedback("edge (%d,%d) does not exist", c[i], c[(i+1)%k]);

    string trailing;
    if(sol >> trailing) feedback("Trailing output");
    return true;
  };

  bool judge_found_even = check(judge_ans, judge_error);
  bool author_found_even = check(author_out, wrong_answer);

  if(!judge_found_even && author_found_even)
    judge_error("NO! Solution found a cycle, but judge says none exists");

  if(judge_found_even && !author_found_even)
    wrong_answer("Cycle exists, but solution did not find it");

  accept();
}
