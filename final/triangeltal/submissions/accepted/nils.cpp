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

bool check(vector<pii> solution){ // pairs of (max(group), size(group))
    if(sz(solution) != k)return 0;
    rep(c1,0,k){
        if(solution[c1].first > solution[(c1+1)%k].second)return 0;
    }
    return 1;
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
    int maxa = A[I.back()];

    // 2 3 1
    int i1 = n-1;
    int i2 = maxa-1;
    int i3 = i2 + A[I[i2]];
    if(i2 < i3 && i3 < i1){
        vector<pii> solution = {{maxa, i1-i3}, {A[I[i2]], i2+1}, {A[I[i3]], i3-i2}};
        if(check(solution)){
            intervals = {{i3+1, i1}, {0, i2}, {i2+1, i3}};
        }
    }

    // 3 2 1
    rep(i2, maxa, n-1){
        int i1 = n-1;
        int i3 = i2-maxa;
        if(i3 < i2 && i2 < i1){
            vector<pii> solution = {{maxa, i1-i2}, {A[I[i2]], i2-i3}, {A[I[i3]], i3+1}};
            if(check(solution)){
                intervals = {{i2+1, i1}, {i3+1, i2}, {0, i3}};
            }
        }
    }

    if(sz(intervals) > 0){
        return get_ans(intervals);
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

