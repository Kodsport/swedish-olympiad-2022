#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;

int main(){
    int saves_a,goals_a,shots_a,saves_b,goals_b,shots_b;
    cin>>saves_a>>goals_a>>shots_a>>saves_b>>goals_b>>shots_b;
    if(shots_a==0)saves_b=0,goals_a=0;
    else if(shots_a!=-1 && saves_b!=-1)goals_a=shots_a-saves_b;
    else if(shots_a!=-1 && goals_a!=-1)saves_b=shots_a-saves_b;
    else if(goals_a!=-1 && saves_b!=-1)shots_a=goals_a+saves_b;
    if(shots_b==0)saves_a=0,goals_b=0;
    else if(shots_b!=-1 && saves_a!=-1)goals_b=shots_b-saves_a;
    else if(shots_b!=-1 && goals_b!=-1)saves_a=shots_b-saves_a;
    else if(goals_b!=-1 && saves_a!=-1)shots_b=goals_b+saves_a;
    cout<<saves_a<<" "<<goals_a<<" "<<shots_a<<endl;
    cout<<saves_b<<" "<<goals_b<<" "<<shots_b<<endl;
    return 0;
}