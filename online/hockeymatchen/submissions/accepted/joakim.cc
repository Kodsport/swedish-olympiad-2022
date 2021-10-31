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

    auto fix = [&](ll &a, ll &b, ll &c) { // a+b=c;
        if(a == -1 && b != -1 && c != -1) a = c-b;
        if(a != -1 && b == -1 && c != -1) b = c-a;
        if(a != -1 && b != -1 && c == -1) c = a+b;
        if(a == -1 && b == -1 && c == 0) a = b = 0; // non-neg constraint
        if(a != -1 && b != -1 && c != -1) assert(a+b == c);
    };
    fix(save1, goal2, shots2);
    fix(save2, goal1, shots1);

    cout << save1 << " " << goal1 << " " << shots1 << endl;
    cout << save2 << " " << goal2 << " " << shots2 << endl;
}
