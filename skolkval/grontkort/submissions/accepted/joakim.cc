#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, m;
    cin >> n >> m;
    assert(n >= 2);
    ll N = n, M = m;

    ll ans = 2 + (n%2);
    if(n%2) m = max<ll>(0, m-n);
    ans += (m+n-1) / n;

    assert((2*N + M) <= N*ans);
    assert(!((2*N + M) <= N*(ans-2)));

    cout << 10 * ans << endl;
}
