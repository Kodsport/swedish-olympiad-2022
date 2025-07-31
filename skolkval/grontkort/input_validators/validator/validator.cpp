#include "validator.h"

typedef long long ll;

void run() {
  int max_n  = Arg("max_n", int(4e8));
  int max_m  = Arg("max_m", int(4e8));

  int n = Int(2, max_n);
  Endl();
  int m = Int(0, max_m);
  Endl();
  Eof();
}
