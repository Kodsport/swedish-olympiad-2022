#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

void run() {
	int n = Int(1, 8);
	Space();
	int m = Int(1, 8);
	Endl();

	for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            char ch = Char();
            assert('0' <= ch && ch <= '4');
        }
        Endl();
    }

}
