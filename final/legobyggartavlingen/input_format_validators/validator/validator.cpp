#include "validator.h"

void run() {
	int a = Int(0, Arg("a"));
	Space();
	int b = Int(0, Arg("b"));
	Space();
	int m = Int(0, Arg("m"));
	Endl();

	vector<pair<int, int>> towers, masts;
	int towerMinX = INT_MAX;
	int mastMaxX = INT_MIN;
	for (int i = 0; i < a + b; i++) {
		int x = Int(0, 1'000'000'000);
		Space();
		int f = Int(0, 1000);
		Space();
		int h = Int(0, 1000);
		Endl();
		towers.push_back({x,h});
		towerMinX = min(towerMinX, x);
	}

	for (int i = 0; i < m; i++) {
		int x = Int(0, 1'000'000'000);
		Space();
		int h = Int(0, 1000);
		Endl();
		masts.push_back({x,h});
		mastMaxX = max(mastMaxX, x);
	}

	for (auto tow : towers) {
		for (auto ma : masts) {
			int dx = abs(tow.first - ma.first);
			assert(tow.second <= ma.second - dx);
		}
	}

	if (Arg("separated")) {
		assert(mastMaxX < towerMinX);
	}
}
