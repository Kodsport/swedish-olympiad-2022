#include <vector>
#include <algorithm>
#include <set>
#include "validate.h"

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

void check_case(){
  int N;

  judge_in >> N;
  vector<string> G(N);
  rep(i,0,N) judge_in >> G[i];

  string ans, cols;
  if (!(author_out >> ans)) {
    wrong_answer("Could not read contestant answer.\n");
  }
  if (!(author_out >> cols)) {
    wrong_answer("Could not read contestant colors.\n");
  }
  if (sz(ans) != sz(cols)) {
    wrong_answer("%d instructions, %d colors.\n", sz(ans), sz(cols));
  }

  vector<string> now(N, string(N, '.'));
  set<char> seen;
  rep(ins,0,sz(ans)) {
    char c = ans[ins];
    if (seen.count(c)) wrong_answer("Painted twice\n");
    seen.insert(c);
    bool row = '1' <= c && c <= '1' + N;
    bool col = 'A' <= c && c <= 'A' + N;
    if (!row && !col) wrong_answer("Invalid ins\n");

    char color = cols[ins];
    if (color != 'S' && color != 'V') wrong_answer("Invalid color\n");

    bool diff = false;
    rep(i,0,N) {
      int rw = row ? c - '1' : i;
      int cl = col ? c - 'A' : i;
      if (now[rw][cl] != color) diff = true;
      now[rw][cl] = color;
    }
    if (!diff) wrong_answer("Unnecessary paint");
  }
  if (G != now) wrong_answer("Incorrect result");
}

int main(int argc, char **argv) {
  init_io(argc, argv);
  check_case();
  string trash;
  if (author_out >> trash) {
    wrong_answer("Trailing output\n");
  }
  accept();
  return 0;
}
