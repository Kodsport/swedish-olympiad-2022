#include "validator.h"
void run()
{
    int sum_m=Arg("sum_m");
    bool disjoint = Arg("disjoint", 0);
    int max_coordinate=Arg("max_coordinate");
    int n = Int(1, sum_m);
	Endl();
    for(int i=0;i<n;i++){
        int m=Int(0,sum_m);
        sum_m-=m;
        set<pair<int,int>> intervals;
        for(int j=0;j<m;j+=2){
            int a=Int(0,max_coordinate);
            Space();
            int b=Int(a,max_coordinate);
            Space();
            intervals.emplace(a,b);
        }
        Endl();
        if(disjoint){
            int cur_r=-1;
            for(pair<int,int> a:intervals){
                assert(cur_r<a.first);
                cur_r=a.second;
            }
        }
    }
    assert(sum_m==0);
    Eof();
}
