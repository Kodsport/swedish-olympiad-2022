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

    vi used(300);

    function<void()> rec = [&]() {
        bool done = true;
        rep(i,0,n) rep(j,0,n) if(v[i][j] == 'V' || v[i][j] == 'S') {
            done = false;
            goto breaaak;
        }
breaaak:;

        auto go = [&](char where, const auto& at) {
            if(used[where]) return;
            vi cnt(300);
            rep(j,0,n) ++cnt[at(j)];
            if(cnt['.']) return;
            if(cnt['S'] && cnt['V']) return;
            string prev(n,'?');
            rep(j,0,n) prev[j] = at(j);

            for(char c : {'S', 'V'}) {
                if(cnt[c^'S'^'V'] == 0) {
                    used[where] = 1;
                    where_ans += where;
                    color_ans += c;
                    rep(j,0,n) at(j) = 'X';

                    rec();

                    rep(j,0,n) at(j) = prev[j];

                    used[where] = 0;
                    where_ans.pop_back();
                    color_ans.pop_back();
                }
            }
        };

        rep(i,0,n) go('1'+i, [&](int j)->char&{return v[i][j];});
        rep(j,0,n) go('A'+j, [&](int i)->char&{return v[i][j];});

        if(done) {
            for(int i = sz(where_ans); i--;) cout << where_ans[i];
            cout << endl;
            for(int i = sz(color_ans); i--;) cout << color_ans[i];
            cout << endl;
            cout << endl;
        }
    };

    rec();
}
