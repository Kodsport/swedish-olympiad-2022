#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;
vector<string> args;
string cmdlinearg(string name)
{
    trav(a, args)
    {
        if (a.size() < name.size() + 1)
            continue;
        bool good = 1;
        rep(i, 0, name.size())
        {
            if (a[i] != name[i])
            {
                good = 0;
                break;
            }
            if (a[name.size()] != '=')
                good = 0;
        }
        if (good)
        {
            string res = "";
            rep(i, name.size() + 1, a.size()) res += a[i];
            return res;
        }
    }
    cout << "paremeter " << name << " not found" << endl;
    assert(0);
}
ll convert_to_int(string s)
{
    ll val = 0;
    reverse(all(s));
    ll power = 1;
    rep(i, 0, s.size()) val += power * (s[i] - '0'), power *= 10;
    return val;
}
void both_zero(){
    cout<<-1<<" "<<-1<<" "<<0<<endl;
    cout<<-1<<" "<<-1<<" "<<0<<endl;
}
void one_zero(ll max_value){
    ll a=rand()%max_value+1;
    ll b=rand()%(max_value+1-a);
    if(rand()%2){   
        cout<<((rand()%2)?a:-1)<<" "<<-1<<" "<<0<<endl;
        cout<<-1<<" "<<((rand()%2)?b:-1)<<" "<<((rand()%2)?-1:a+b)<<endl;
    }
    else{
        cout<<-1<<" "<<((rand()%2)?b:-1)<<" "<<((rand()%2)?-1:a+b)<<endl;
        cout<<((rand()%2)?a:-1)<<" "<<-1<<" "<<0<<endl;
    }
}
void doable(ll max_value){
    ll a=rand()%max_value+1;
    ll b=rand()%(max_value+1-a);
    ll c=rand()%max_value+1;
    ll d=rand()%(max_value+1-c);
    if(rand()%2){
    cout<<a<<" "<<c<<" "<<-1<<endl;
    cout<<d<<" "<<-1<<" "<<a+b<<endl;
    }
    else {
        cout<<-1<<" "<<-1<<" "<<c+d<<endl;
    cout<<d<<" "<<b<<" "<<a+b<<endl;
    }
}
void no_restrictions(ll max_value){
    ll a=rand()%(max_value - 1)+1;
    ll b=rand()%(max_value - a)+1;
    ll c=rand()%(max_value - 1)+1;
    ll d=rand()%(max_value - c)+1;
    cout<<((rand()%2)?c:-1)<<" "<<((rand()%2)?a:-1)<<" "<<((rand()%2)?a+b:-1)<<endl;
    cout<<((rand()%2)?b:-1)<<" "<<((rand()%2)?d:-1)<<" "<<((rand()%2)?c+d:-1)<<endl;
}
int main(int argc, char **argv)
{
    // The areguments should be in this format:
    // seed=(seed) max_value=(max_value) type=(type)
    // There are four types: 1=> both teams have zero shots, 2 => one team has zero shots , 3 => one unkown per equation,
    // 4 => no restrictions
    rep(i, 0, argc) args.push_back(argv[i]);
    ll seed = convert_to_int(cmdlinearg("seed"));
    ll max_value=convert_to_int(cmdlinearg("max_value"));
    max_value--;
    ll type=convert_to_int(cmdlinearg("type"));
    srand(seed);
    if(type==1){
        both_zero();
    }
    else if(type==2){
        one_zero(max_value);
    }
    else if(type==3){
        doable(max_value);
    }
    else no_restrictions(max_value);
    return 0;
}
