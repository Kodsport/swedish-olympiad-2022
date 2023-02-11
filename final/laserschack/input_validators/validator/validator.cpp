#include "validator.h"
#include <bits/stdc++.h>

using namespace std;

void run() {
	int exactR = Arg("r");
	int maxRC = Arg("maxRC");
	string mode = Arg("mode");

	int r = Int(1, 1000000);
	Space();
	int c = Int(1, 1000000);
	Endl();

	if(exactR!=-1)
		assert(r==exactR);

	std::cout<<r<<std::endl;
	std::cout<<c<<std::endl;
	std::cout<<maxRC<<std::endl;
	assert(r*c<=maxRC);


	vector<string> g(r, string(c, '\0'));
	int numR = 0;
	int numA = 0;
	int numK = 0;
	int numAir = 0;
    int ar,ac;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char c = Char();
			assert(c == 'R' || c == 'A' || c=='K' || c=='o' || c=='.');
			g[i][j] = c;
			if(c=='R') numR++;
			if(c=='A') numA++;
			if(c=='K') numK++;
			if(c=='.') numAir++;
            if(g[i][j]=='A'){
                ar = i;
                ac = j;
            }
		}
		Endl();
	}

	assert(numR>=1);
	assert(numA==1);
	assert(numK==1);
	if(mode=="singleR") assert(numR==1);
	else if(mode=="noair") assert(numAir==0);
	else assert(mode=="none");

	// Check solvability
	queue<tuple<int,int>> q;
    q.emplace(ar,ac);
    vector<vector<bool>> seen(r,vector<bool>(c));
	bool solved = false;
    while(q.size()){
        int x,y;
        tie(x,y) = q.front();
		q.pop();
        if(seen[x][y]) continue;
        seen[x][y] = true;
        if(g[x][y]=='K') {
			solved = true;
			break;
        }

        for(auto &dir: vector<pair<int,int>>({{0,1},{0,-1},{1,0},{-1,0}})){
            int xi = x;
            int yi = y;
            while(true) {
                xi += dir.first;
                yi += dir.second;
                if(xi<0 || xi>=r || yi<0 || yi>=c) break;
                if(g[xi][yi]=='R') break;
                if(g[xi][yi]=='o' || g[xi][yi]=='K'){
                    q.emplace(xi,yi);
                    break;
                }
            }
        }
    }
	assert(solved);
}
