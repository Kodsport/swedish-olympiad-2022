#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1000001;

int n,k;
vi A, I;

bool comp(int i, int j){
    return A[i] < A[j];
}

string get_ans(vector<pii> intervals){
    string digits = "0123456789";
    vector<char> L(n, '0');
    rep(c1,0,n){
        rep(c2,0,k){
            if(intervals[c2].first <= c1 && c1 <= intervals[c2].second){
                L[I[c1]] = digits[c2+1];
            }
        }
    }
    string res = "";
    rep(c1,0,n){
        res += L[c1];
    }
    return res;
}

string solve3(){
    vector<pii> intervals;

    rep(x,0,n-1){
        rep(y,x+1,n-1){
            int z = n-1;
            // 2 3 1
            if(A[I[z]] <= x+1 && A[I[x]] <= y-x && A[I[y]] <= z-y){
                intervals = {{y+1,z}, {0,x}, {x+1,y}};
                return get_ans(intervals);
            }
            // 3 2 1
            if(A[I[z]] <= y-x && A[I[y]] <= x+1 && A[I[x]] <= z-y){
                intervals = {{y+1,z}, {x+1,y}, {0,x}};
                return get_ans(intervals);
            }
        }
    }
    return "NO";
}

int main() {
    cin >> n;
	k = 3;
    rep(c1,0,n){
        int a;
        cin >> a;
        A.push_back(a);
        I.push_back(c1);
    }

    sort(all(I), comp);
    string ans = solve3();
    if(ans != "NO"){
        cout << "YES\n";
    }
    cout << ans << "\n";

    return 0;
}

