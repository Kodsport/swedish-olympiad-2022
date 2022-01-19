#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main(int argc, char **argv) {
  init_io(argc, argv);

  int n, k;
  judge_in >> n;
  k = 3;

  vi A;
  rep(c1,0,n) {
    int a;
    judge_in >> a;
    A.push_back(a);
  }

  auto check = [&](istream& sol, feedback_function feedback){
    string ans;
    if(!(sol >> ans)) feedback("Expected more output");
    for (char& c : ans) c = (char)toupper(c);
    if(ans != "NO" && ans != "YES")
      feedback("Answer \'%s\' is not {YES|NO}", ans.c_str());

    if(ans == "NO"){
      string trailing;
      if(sol >> trailing) feedback("Trailing output");
      return false;
    }

    if(!(sol >> ans)) feedback("Expected more output");
    if(sz(ans) != n) feedback("Length of output was %d instead of %d", sz(ans), n);
    rep(c1,0,n){
      if(ans[c1]-'0' < 1 || ans[c1]-'0' > k) feedback("Output contained invalid character");
    }

    vector<pii> solution(k, {-1, 0});  // Pairs (max(group), size(group))
    rep(c1,0,n){
      int i = ans[c1]-'1';
      solution[i].first = max(solution[i].first, A[c1]);
      solution[i].second++;
    }

    rep(c1,0,k){
      if(solution[c1].first > solution[(c1+1)%k].second){
        int g_max = solution[c1].first;
        int g_size = solution[(c1+1)%k].second;
        feedback("Max of group %d (%d) was bigger than size of the next group (%d)",c1+1,g_max,g_size);
      }
    }

    string trailing;
    if(sol >> trailing) feedback("Trailing output");
    return true;
  };

  bool judge_found = check(judge_ans, judge_error);
  bool author_found = check(author_out, wrong_answer);

  if(!judge_found && author_found)
    judge_error("Judge said no, but contestant found a solution");

  if(judge_found && !author_found)
    wrong_answer("Contestant said no, but judge found a solution");

  accept();
}
