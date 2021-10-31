// @EXPECTED_GRADES@ RTE AC RTE
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll save1, goal1, shots1;
  cin >> save1 >> goal1 >> shots1;
  ll save2, goal2, shots2;
  cin >> save2 >> goal2 >> shots2;

  vector<tuple<int,int,int,int,int,int>> solutions;
  rep(sv1,0,16) rep(sv2,0,16) rep(go1,0,16) rep(go2,0,16) rep(sh1,0,16) rep(sh2,0,16) {
    if(save1 != -1 && save1 != sv1) continue;
    if(save2 != -1 && save2 != sv2) continue;
    if(shots1 != -1 && shots1 != sh1) continue;
    if(shots2 != -1 && shots2 != sh2) continue;
    if(goal1 != -1 && goal1 != go1) continue;
    if(goal2 != -1 && goal2 != go2) continue;

    if(sv1 + go2 != sh2) continue;
    if(sv2 + go1 != sh1) continue;
    solutions.emplace_back(sv1,go1,sh1,sv2,go2,sh2);
  }
  assert(sz(solutions));
  auto sol = solutions[0];
  for(auto t : solutions) {
#define go(x) if(get<x>(sol) != get<x>(t)) get<x>(sol) = -1;
    go(0);
    go(1);
    go(2);
    go(3);
    go(4);
    go(5);
  }
#define pr(x) cout << get<x>(sol) << " ";
  pr(0);
  pr(1);
  pr(2);
  cout << endl;
  pr(3);
  pr(4);
  pr(5);
  cout << endl;
}
