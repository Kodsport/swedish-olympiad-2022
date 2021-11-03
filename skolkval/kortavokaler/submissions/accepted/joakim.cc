#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, vowels = "aeiouy";
  cin >> s;
  long long none = 1, one = 0, many = 0;
  reverse(begin(s),end(s));
  for(char c : s) {
    tie(none,one,many) =
      count(begin(vowels),end(vowels),c)
      ? make_tuple(none+none+one, one, many)
      : make_tuple(none, one+none, many+one+many);
  }
  cout << none + one + many - 1 << endl;
}

