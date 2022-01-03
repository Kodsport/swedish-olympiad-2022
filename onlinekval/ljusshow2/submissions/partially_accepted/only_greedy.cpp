#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

int n,m;
int inf = 1000000000;
vector<bitset<MAXN>> rows(MAXN, bitset<MAXN>());

string mask_to_string[7] = {"XX", "RR", "GG", "RG", "BB", "BR", "BG"};

struct TC{
    vector<int> col_mask, row_mask;
    TC(int n, int m){
        col_mask.assign(m, 0);
        row_mask.assign(n, 0);
    }
};

void print_tc(TC tc){
    for(int b = 0; b <= 1; b++){
        for(int c1 = 0; c1 < m; c1++){
            cout << mask_to_string[tc.col_mask[c1]][b];
        }cout << "\n";
        for(int c1 = 0; c1 < n; c1++){
            cout << mask_to_string[tc.row_mask[c1]][b];
        }cout << "\n";
    }
}

int row_score(TC &tc, int i){
    int res = 0;
    for(int c1 = 0; c1 < m; c1++){
        if(tc.col_mask[c1] != 0 && tc.row_mask[i] != 0){
            res += (((tc.col_mask[c1]|tc.row_mask[i])==7)==rows[i][c1]);
        }
    }
    return res;
}

int col_score(TC &tc, int i){
    int res = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(tc.row_mask[c1] != 0 && tc.col_mask[i] != 0){
            res += (((tc.col_mask[i]|tc.row_mask[c1])==7)==rows[c1][i]);
        }
    }
    return res;
}

int score(TC &tc){
    int res = 0;
    for(int c1 = 0; c1 < n; c1++){
        res += row_score(tc, c1);
    }
    return 2*res-n*m;
}


TC greedy(){
    vector<int> ind;
    for(int c1 = 0; c1 < n+m; c1++){
        ind.push_back(c1);
    }
    random_shuffle(ind.begin(), ind.end());
    TC tc(n, m);
    for(auto i : ind){
        if(i < n){
            int best = -inf;
            int best_mask = 1;
            for(int mask = 1; mask < 7; mask++){
                tc.row_mask[i] = mask;
                int temp = row_score(tc, i);
                if(temp > best){
                    best = temp;
                    best_mask = mask;
                }
            }
            tc.row_mask[i] = best_mask;
        }
        else{
            i -= n;
            int best = -inf;
            int best_mask = 1;
            for(int mask = 1; mask < 7; mask++){
                tc.col_mask[i] = mask;
                int temp = col_score(tc, i);
                if(temp > best){
                    best = temp;
                    best_mask = mask;
                }
            }
            tc.col_mask[i] = best_mask;
        }
    }
    return tc;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    cin >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;
        for(int c2 = 0; c2 < m; c2++){
            rows[c1][c2] = (s[c2]-'0');
        }
    }

    int best_score = -inf;
    TC ans(n, m);

    int LIM = 7000000 / (n*m);
    for(int c1 = 0; c1 < LIM; c1++){
        TC tc = greedy();
        int sc = score(tc);
        if(sc > best_score){
            best_score = sc;
            ans = tc;
        }
    }

    print_tc(ans);


    return 0;
}

