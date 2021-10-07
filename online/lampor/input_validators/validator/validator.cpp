#include "validator.h"

typedef long long ll;

int ReadLn(int len) {
    int have = 0;
	for (int j = 0; j < len; j++) {
		char ch = Char();
        if (ch == 'R') have |= 1;
        else if (ch == 'G') have |= 2;
        else if (ch == 'B') have |= 4;
        else assert(false && "Invalid char");
	}
	Endl();
    return have;
}

void run() {
	int task  = Arg("task");

    int maxD = (task == 3) ? 1'000 : 1'000'000;
    int R = Int(1, maxD); Space();
    int C = Int(1, maxD); Endl();

    int ucols = ReadLn(C);
    int rcols = ReadLn(R);
    int bcols = ReadLn(C);
    int lcols = ReadLn(R);

    if (task == 2) {
        assert(__builtin_popcount(ucols) == 1 && "All lamps on a side must have the same color");
        assert(__builtin_popcount(rcols) == 1 && "All lamps on a side must have the same color");
        assert(__builtin_popcount(bcols) == 1 && "All lamps on a side must have the same color");
        assert(__builtin_popcount(lcols) == 1 && "All lamps on a side must have the same color");
    }
    if (task == 4) {
        assert(rcols == 1 && lcols == 1 && "Horizontal lamps must be red");
        assert((ucols&1) == 0 && (bcols&1) == 0 && "Vertical lamps must be non-red");
    }
}
