#include "validator.h"

void run() {
	int abmLim = Arg("abm");
	int a = Int(1, abmLim);
	Space();
	int b = Int(1, abmLim);
	Space();
	int m = Int(1, abmLim);
	Endl();

	vector<pair<int, int>> towers, masts;
	int towerMinX = INT_MAX;
	int mastMaxX = INT_MIN;
	set<int> towersX;
	for (int i = 0; i < a + b; i++) {
		int x = Int(1, 1'000'000);
		Space();
		int f = Int(1, 100);
		Space();
		int h = Int(1, 10000);
		Endl();
		towers.push_back({x,h});
		towerMinX = min(towerMinX, x);
		towersX.insert(x);
	}
	assert((int)towersX.size() == a + b);

	set<int> mastsX;
	for (int i = 0; i < m; i++) {
		int x = Int(1, 1'000'000);
		Space();
		int h = Int(1, 10000);
		Endl();
		masts.push_back({x,h});
		mastsX.insert(x);
		mastMaxX = max(mastMaxX, x);
	}
	assert((int)mastsX.size() == m);

	for (auto tow : towers) {
		for (auto ma : masts) {
			int dx = abs(tow.first - ma.first);
			if (tow.second <= ma.second - dx) goto found;
		}
		assert(0 && "not covered initially");
found:;
	}

	if (Arg("separated", 0)) {
		assert(mastMaxX < towerMinX);
	}
}
