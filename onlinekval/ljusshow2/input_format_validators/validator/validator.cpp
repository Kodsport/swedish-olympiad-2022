#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

void run() {
    int T = Int(0, 10);
	assert(T == (int)Arg("t"));
    Endl();
	int n = Int(1, 1000);
	Space();
	int m = Int(1, 1000);
	Endl();

	for(int c1 = 0; c1 < n; c1++){
        string row = Line();
        assert(row.length() == m);
        for(int c2 = 0; c2 < m; c2++){
            assert(row[c2] == '0' || row[c2] == '1');
        }
    }

}