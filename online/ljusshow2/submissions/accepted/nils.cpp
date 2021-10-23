#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

int n,m;
int inf = 1000000000;
vector<bitset<MAXN>> rows(MAXN, bitset<MAXN>());
vector<bitset<MAXN>> cols(MAXN, bitset<MAXN>());

vector<int> parent_row;
vector<int> parent_col;

vector<int> unique_rows;
vector<int> unique_cols;

string mask_to_string[7] = {"XX", "RR", "GG", "RG", "BB", "BR", "BG"};

vector<int> answer_rows;
vector<int> answer_cols;

bool used[2][7] = {0};

bool check_answer(){
    for(int c1 = 0; c1 < unique_rows.size(); c1++){
        for(int c2 = 0; c2 < unique_cols.size(); c2++){
            if(answer_rows[c1] != 0 && answer_cols[c2] != 0){
                int i = unique_rows[c1];
                int j = unique_cols[c2];
                if(((answer_rows[c1] | answer_cols[c2]) == 7) != rows[i][j] )return 0;
            }
        }
    }
    return 1;
}

bool brute_force(bool row, int i){
    if(i == unique_rows.size() && row)return brute_force(0, 0);
    if(i == unique_cols.size() && !row){
        bool temp = check_answer();
        return temp;
    }
    if(!check_answer())return 0;
 //   cerr << row << " " << i << "  b\n";
    for(int mask = 1; mask <= 6; mask++){
        if(!used[row][mask]){
            used[row][mask] = 1;
            if(row){
                answer_rows[i] = mask;
            }
            else{
                answer_cols[i] = mask;
            }
            bool temp = brute_force(row, i+1);
            if(temp)return 1;
            used[row][mask] = 0;
            if(row){
                answer_rows[i] = 0;
            }
            else{
                answer_cols[i] = 0;
            }
        }
    }
    return 0;
}


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
    // Shuffle the rows/columns, greedily pick lamps that increase answer the most.
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
            cols[c2][c1] = (s[c2]-'0');
        }
    }

    if(T <= 7){
        // Solve exactly
        for(int c1 = 0; c1 < n; c1++){
            bool seen_before = 0;
            for(int c2 = 0; c2 < unique_rows.size(); c2++){
                if(rows[c1] == rows[unique_rows[c2]]){
                    seen_before = 1;
                    parent_row.push_back(c2);
                    break;
                }
            }
            if(!seen_before){
                parent_row.push_back(unique_rows.size());
                unique_rows.push_back(c1);
            }
        }
        for(int c1 = 0; c1 < m; c1++){
            bool seen_before = 0;
            for(int c2 = 0; c2 < unique_cols.size(); c2++){
                if(cols[c1] == cols[unique_cols[c2]]){
                    seen_before = 1;
                    parent_col.push_back(c2);
                    break;
                }
            }
            if(!seen_before){
                parent_col.push_back(unique_cols.size());
                unique_cols.push_back(c1);
            }
        }

        answer_rows.assign(unique_rows.size(), 0);
        answer_cols.assign(unique_cols.size(), 0);

        bool res = brute_force(1, 0);

        for(int b = 0; b <= 1; b++){
            for(int c1 = 0; c1 < m; c1++){
                int i = parent_col[c1];
                cout << mask_to_string[answer_cols[i]][b];
            }
            cout << "\n";
            for(int c1 = 0; c1 < n; c1++){
                int i = parent_row[c1];
                cout << mask_to_string[answer_rows[i]][b];
            }
            cout << "\n";
        }
    }
    else{
        // Greedy heuristic
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
        cerr << T << ": " << double(best_score)/2.0 << "\n";
    }

    return 0;
}

