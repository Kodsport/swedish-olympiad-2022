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
    TC(){}
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

vector<int> get_mask_counts(vector<int> &masks, bitset<MAXN> &row){
    vector<int> ans(13, 0);
    for(int c1 = 0; c1 < masks.size(); c1++){
        int a = masks[c1] + 6 * (masks[c1] != 0 & row[c1]);
        ans[a]++;
    }
    return ans;
}

int potential(vector<int> &mask_counts, int mask){
    // Gets the score of a row or column, given info on how many of each (mask, lamp)
    // pair is on this row/column. This takes O(1) since there are only 13 distinct
    // (mask, lamp) pairs. Computing mask_counts still takes O(n), but different masks
    // can be considered without extra cost, so this cuts down time with a factor ~6.
    int res = 0;
    for(int c1 = 1; c1 < mask_counts.size(); c1++){
        bool row_entry = (c1 > 6);
        int temp_mask = c1 - int(row_entry) * 6;
        res += mask_counts[c1] * (((mask | temp_mask) == 7) == row_entry);
    }
    return res;
}

bool hillclimb(TC &tc){
    // Go through each row and column, check if score can be increased by changing it.
    bool improvement = 0;
    for(int i = 0; i < n; i++){
        int best_mask = tc.row_mask[i];
        vector<int> mask_counts = get_mask_counts(tc.col_mask, rows[i]);
        int old_score = potential(mask_counts, best_mask);

        for(int mask = 1; mask < 7; mask++){
            int new_score = potential(mask_counts, mask);
            if(new_score > old_score){
                old_score = new_score;
                best_mask = mask;
                improvement = 1;
            }
        }
        tc.row_mask[i] = best_mask;
    }
    for(int i = 0; i < m; i++){
        int best_mask = tc.col_mask[i];
        vector<int> mask_counts = get_mask_counts(tc.row_mask, cols[i]);
        int old_score = potential(mask_counts, best_mask);

        for(int mask = 1; mask < 7; mask++){
            int new_score = potential(mask_counts, mask);
            if(new_score > old_score){
                old_score = new_score;
                best_mask = mask;
                improvement = 1;
            }
        }
        tc.col_mask[i] = best_mask;
    }
    return improvement;
}

int score(TC &tc){
    int res = 0;
    for(int c1 = 0; c1 < n; c1++){
        vector<int> mask_counts = get_mask_counts(tc.col_mask, rows[c1]);
        res += potential(mask_counts, tc.row_mask[c1]);
    }
    return 2*res-n*m;
}

vector<int> all_masks = {1,2,3,4,5,6};
int best_score = -inf;
TC ans;
vector<int> best_ind;

void greedy(int swaps){
    // Shuffle the rows/columns, greedily pick lamps that increase answer the most.
    vector<int> ind;
    if(best_ind.size() > 0){
        ind = best_ind;
    }
    else{
        for(int c1 = 0; c1 < n+m; c1++){
            ind.push_back(c1);
        }
    }
    if(swaps == -1){
        random_shuffle(ind.begin(), ind.end());
    }
    else{
        for(int c1 = 0; c1 < swaps; c1++){
            int i = rand()%(n+m);
            int j = rand()%(n+m);
            swap(ind[i], ind[j]);
        }
    }
    TC tc(n, m);
    for(auto i : ind){
        if(i < n){
            int best = -inf;
            int best_mask = 1;
            vector<int> mask_counts = get_mask_counts(tc.col_mask, rows[i]);
            random_shuffle(all_masks.begin(), all_masks.end());
            for(int c1 = 0; c1 < 6; c1++){
                int mask = all_masks[c1];
                int temp = potential(mask_counts, mask);
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
            vector<int> mask_counts = get_mask_counts(tc.row_mask, cols[i]);
            random_shuffle(all_masks.begin(), all_masks.end());
            for(int c1 = 0; c1 < 6; c1++){
                int mask = all_masks[c1];
                int temp = potential(mask_counts, mask);
                if(temp > best){
                    best = temp;
                    best_mask = mask;
                }
            }
            tc.col_mask[i] = best_mask;
        }
    }

    int tries = 0;
    while(1){
        bool hc = hillclimb(tc);
        tries++;
        if(!hc ||tries > 50)break;
    }

    int sc = score(tc);
    if(sc > best_score){
        //cerr << sc/2 << "  tries: " << tries << "\n";
        best_score = sc;
        ans = tc;
        best_ind = ind;
    }
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
        int LIM1, LIM2;

        if(T == 8){LIM1 = 100000; LIM2 = 1000;}
        if(T == 9){LIM1 = 10000; LIM2 = 10;}
        if(T == 10){LIM1 = 40; LIM2 = 20;}

        for(int c1 = 0; c1 < LIM1; c1++){
            greedy(-1);
        }
        for(int c1 = 0; c1 < LIM2; c1++){
            greedy(4);
        }
        while(hillclimb(ans)){}
        print_tc(ans);
        cerr << T << ": " << double(best_score)/2.0 << "\n";
    }

    return 0;
}

