#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int remove_paint(vector<vector<char> > &grid){
    rep(h,0,2){
        rep(i,0,sz(grid)){
            bool empty = false; 
            bool s = false; 
            bool v = false; 
            rep(j,0,sz(grid[0])){
                if (h == 0){
                    if (grid[i][j] == '.') empty = true; 
                    else if (grid[i][j] == 'S') s = true; 
                    else if (grid[i][j] == 'V') v = true; 
                }
                else{
                    if (grid[j][i] == '.') empty = true; 
                    else if (grid[j][i] == 'S') s = true; 
                    else if (grid[j][i] == 'V') v = true; 
                }
            }
            if (empty) continue; 
            if (s+v == 1){
                rep(j,0,sz(grid[0])){
                    if (h == 0) grid[i][j] = '?';
                    else grid[j][i] = '?';  
                }
            }
            if (s && !v) return 1; 
            if (!s && v) return 2; 
        }
    }
    return 0; 
}

int main(){
    cin.sync_with_stdio(0);
    int n; 
    cin >> n; 

    vector<vector<char> > grid(n, vector<char>(n, '.')); 
    rep(i,0,n) rep(j,0,n) cin >> grid[i][j]; 

    int s = 0; 
    int v = 0; 
    while (true){
        int r = remove_paint(grid); 
        if (r == 0) break; 
        else if (r == 1) s++; 
        else if (r == 2) v++; 
    }

    cout << s << " " << v << endl; 
}
