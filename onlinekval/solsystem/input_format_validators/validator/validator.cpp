#include "validator.h"
void run()
{
  int max_n = Arg("max_n");
  int max_q = Arg("max_q");
  int max_r = Arg("max_r");
  bool increasing = Arg("increasing", 0);
  int n = Int(1, max_n);
  Endl();
  int b = 0;
  int last_l = 0, last_r = 0;
  for (int i = 0; i < n; i++)
  {
    int l = Int(1, max_r);
    Space();
    int r = Int(1, max_r);
    if (l > r)
    {
      die_line("r_i is less than l_i");
    }
    if (increasing && l <= last_l)
    {
      die_line("left end points are not increasing");
    }
    if (increasing && r <= last_r)
    {
      die_line("right end points are not decreasing");
    }
    last_l = l;
    last_r = r;
    Endl();
  }
  int q = Int(1, max_q);
  Endl();
  for (int i = 0; i < q; i++)
  {
    int A = Int(1, max_r);
    Space();
    int B = Int(1, max_r);
    assert(A != B);
    Endl();
  }
  Eof();
}
