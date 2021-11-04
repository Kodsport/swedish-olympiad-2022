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
    int n;
    cin>>n;
    vector<string> v(n);
    rep(i,0,n) cin>>v[i];
    string where_ans, color_ans;

    bool done = false;
    while(!done) {
        done = true;
        auto go = [&](char where, const auto& at) {
            vi cnt(300);
            rep(j,0,n) ++cnt[at(j)];
            if(cnt['.']) return;
            if((cnt['S']>0) == (cnt['V']>0)) return;
            where_ans += where;
            color_ans += cnt['S'] ? 'S' : 'V';
            rep(j,0,n) at(j) = 'X';
            done = false;
        };
        rep(i,0,n) go('1'+i, [&](int j)->char&{return v[i][j];});
        rep(j,0,n) go('A'+j, [&](int i)->char&{return v[i][j];});
    }

    reverse(all(where_ans));
    reverse(all(color_ans));
    cout << where_ans << endl;
    cout << color_ans << endl;
}
