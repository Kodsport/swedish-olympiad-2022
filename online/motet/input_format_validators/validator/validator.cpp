#include "validator.h"
void run()
{
    int sum_m = Arg("sum_m");
    bool disjoint = Arg("disjoint", 0);
    int max_coordinate = Arg("max_coordinate");
    int n = Int(1, sum_m);
    Endl();

    int b = 0;
    for (int i = 0; i < n; i++)
    {
        int m = Int(0, sum_m);
        b += m;
        set<pair<int, int>> intervals;
        for (int j = 0; j < m; j++)
        {
            Space();
            int a = Int(0, max_coordinate);
            Space();
            int b = Int(a, max_coordinate);
            intervals.emplace(a, b);
        }
        Endl();
        if (disjoint)
        {
            int cur_r = -1;
            for (pair<int, int> a : intervals)
            {
                if(cur_r >= a.first) die_line("intervals overlap");
                cur_r = a.second;
            }
        }
    }
    if(b > sum_m)
        die_line("[B is too large] "
                "Actual:" + to_string(b) + "; "
                "Expected: <= " + to_string(sum_m));

    Eof();
}
