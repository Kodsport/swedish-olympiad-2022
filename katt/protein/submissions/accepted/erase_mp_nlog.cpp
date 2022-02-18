#include <cstdio>
#include <string>
#include <vector>
using namespace std;
#define data pominki
#define sz(s) ((int) (s).size())
const int L = 20;
const int N = (int) 1e6 + 10;
const int M = 26;
const int H = 2;
const int MOD = (int) 1e9 + 7;
const int P[] = {17239, 23917};
int n, m, best[N], go[L][N], ppow[H][N];
bool can[M][M];
char ch, s[N];

struct data {
  int len, h[H];
  data() {}
  data(char c): len(1) {
    for (int ih = 0; ih < H; ++ih) {
      h[ih] = c;
    }
  }
} str[L][N];

data operator+(const data& a, const data& b) {
  data c;
  c.len = a.len + b.len;
  for (int ih = 0; ih < H; ++ih) {
    c.h[ih] = (a.h[ih] * 1LL * ppow[ih][b.len] + b.h[ih]) % MOD;
  }
  return c;
}

bool operator==(const data& a, const data& b) {
  if (a.len != b.len) return false;
  for (int ih = 0; ih < H; ++ih) {
    if (a.h[ih] != b.h[ih]) return false;
  }
  return true;
}

int compare_lex(int si, int sj) {
  int i = si, j = sj;
  for (int k = L - 1; k >= 0; --k) {
    if (str[k][i] == str[k][j]) {
      i = go[k][i];
      j = go[k][j];
    }
  }
  if ((i == n) || (j == n)) return (i == n) ? si : sj;
  return (s[i] < s[j]) ? si : sj;
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf(" %c", &ch), can[i][j] = (ch == '1');
    }
  }
  scanf("%s", s);
  for (int ih = 0; ih < H; ++ih) {
    ppow[ih][0] = 1;
    for (int i = 0; i < n; ++i) {
      ppow[ih][i + 1] = (ppow[ih][i] * 1LL * P[ih]) % MOD;
    }
  }
  vector<int> cur;
  go[0][n] = n;
  for (int i = n - 1; i >= 0; --i) {
    best[i] = i + 1;      
    while (!cur.empty() && can[s[i] - 'a'][s[cur.back()] - 'a']) {
      best[i] = compare_lex(best[cur.back()], best[i]);
      cur.pop_back();
    }
    cur.push_back(i);
    go[0][i] = best[i];
    str[0][i] = data(s[i]);
    for (int j = 1; j < L; ++j) {
      go[j][i] = go[j - 1][go[j - 1][i]];
      str[j][i] = str[j - 1][i] + str[j - 1][go[j - 1][i]]; 
    }
  }
  for (int i = 0; i < n; i = best[i]) {
    printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}

