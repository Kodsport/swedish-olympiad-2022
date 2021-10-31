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
  string s;
  getline(cin,s);
  getline(cin,s);
  string vowels = "aeiouAEIOU";
  auto is_vowel = [&](char c) { return count(all(vowels),c); };
  auto is_consonant = [&](char c) { return !is_vowel(c) && isalpha(c); };
  rep(i,0,sz(s)) {
    if(i+2 < sz(s) && is_vowel(s[i]) && is_consonant(s[i+1]) && is_consonant(s[i+2]))
      s.erase(begin(s)+i);
  }
  reverse(all(s));
  cout << s << endl;
}