#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

int main() {
    int R, C; cin >> R >> C;
    string rup, rdown, rleft, rright;
    cin >> rup >> rleft >> rdown >> rright;
    ll vR = 0, vG = 0, vB = 0, vRG = 0, vGB = 0, vBR = 0;
    ll hR = 0, hG = 0, hB = 0, hRG = 0, hGB = 0, hBR = 0;
    rep(i, 0, C) {
        switch (rup[i]) {
            case 'R':
                switch (rdown[i]) {
                    case 'R': vR++; break;
                    case 'G': vRG++; break;
                    case 'B': vBR++; break;
                }
                break;
            case 'G':
                switch (rdown[i]) {
                    case 'R': vRG++; break;
                    case 'G': vG++; break;
                    case 'B': vGB++; break;
                }
                break;
            case 'B':
                switch (rdown[i]) {
                    case 'R': vBR++; break;
                    case 'G': vGB++; break;
                    case 'B': vB++; break;
                }
                break;
        }
    }
    rep(i, 0, R) {
        switch (rleft[i]) {
            case 'R':
                switch (rright[i]) {
                    case 'R': hR++; break;
                    case 'G': hRG++; break;
                    case 'B': hBR++; break;
                }
                break;
            case 'G':
                switch (rright[i]) {
                    case 'R': hRG++; break;
                    case 'G': hG++; break;
                    case 'B': hGB++; break;
                }
                break;
            case 'B':
                switch (rright[i]) {
                    case 'R': hBR++; break;
                    case 'G': hGB++; break;
                    case 'B': hB++; break;
                }
                break;
        }
    }
    cout <<
        vRG * (hB + hGB + hBR) +
        vGB * (hR + hBR + hRG) +
        vBR * (hG + hRG + hGB) +
        vB * hRG +
        vR * hGB +
        vG * hBR << endl;
}
