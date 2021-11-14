#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;
vector<string> args;
string cmdlinearg(string name, string def)
{
  trav(a, args)
  {
    if (a.size() < name.size() + 1)
      continue;
    bool good = 1;
    rep(i, 0, name.size())
    {
      if (a[i] != name[i])
      {
        good = 0;
        break;
      }
      if (a[name.size()] != '=')
        good = 0;
    }
    if (good)
    {
      string res = "";
      rep(i, name.size() + 1, a.size()) res += a[i];
      return res;
    }
  }
  if (def != "")
    return def;
  cout << "paremeter " << name << " not found" << endl;
  assert(0);
}
ll convert_to_int(string s)
{
  ll val = 0;
  reverse(all(s));
  ll power = 1;
  rep(i, 0, s.size()) val += power * (s[i] - '0'), power *= 10;
  return val;
}
int main(int argc, char **argv)
{
  // The areguments should be in this format:
  // seed=(seed) max_n=(max_n) max_r=(max_r) max_q=(max_q) max_r=(max_r) increasing=(increasing)
  rep(i, 0, argc) args.push_back(argv[i]);
  ll n = convert_to_int(cmdlinearg("max_n", ""));
  ll q = convert_to_int(cmdlinearg("max_q", ""));
  ll max_r = convert_to_int(cmdlinearg("max_r", ""));
  ll increasing = convert_to_int(cmdlinearg("increasing", "0"));
  ll seed = convert_to_int(cmdlinearg("seed", ""));
  srand(seed);
  if (increasing)
  {
    assert(max_r >= 2 * n);
    cout << n << endl;
    rep(i, 1, n + 1)
    {
      cout << i << " " << n + i << endl;
    }
  }
  else
  {
    cout << n << endl;
    rep(i, 0, n)
    {
      cout << 1 + rand() % min(max_r, (ll)1000) << " " << max_r << endl;
    }
  }
  cout << q << endl;
  rep(i, 0, q)
    {
        ll A = 1 + rand() % max_r;
        ll B = 1 + rand() % max_r;
        while (A == B)
            B = 1 + rand() % max_r;
        cout << A << " " << B << endl;
    }
  return 0;
}