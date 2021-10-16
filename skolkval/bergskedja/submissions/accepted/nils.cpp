#include <bits/stdc++.h>
using namespace std;

int n, m;

int DX[4] = {0,0,-1,1};
int DY[4] = {1,-1,0,0};

vector<vector<int> > grid;

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int solve(int mi){
    vector<vector<int>> grid2 = grid;
    priority_queue<int> pq;
    int index = 0;
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            if(grid2[c1][c2] == 0){
                int i = c1*m+c2;
                pq.push(mi * i);
            }
        }
    }
    int ans = -1;
    while(!pq.empty()){
        int a = abs(pq.top());
        pq.pop();
        index++;
        if(a == 0)ans = index;
        int x1 = a/m;
        int y1 = a%m;
        for(int c1 = 0; c1 < 4; c1++){
            int x2 = x1 + DX[c1];
            int y2 = y1 + DY[c1];
            if(inbounds(x2, y2)){
                grid2[x2][y2]--;
                if(grid2[x2][y2] == 0){
                    pq.push(mi * (x2*m+y2));
                }
            }
        }
    }
    assert(index == n*m);
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;
        vector<int> row;
        for(int c2 = 0; c2 < m; c2++){
            row.push_back(s[c2]-'0');
        }
        grid.push_back(row);
    }

    cout << solve(-1) << " " << solve(1) << "\n";

    return 0;
}

