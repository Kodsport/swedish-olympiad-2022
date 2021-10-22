#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define all(v) v.begin(), v.end()
#define trav(a, v) for (auto &a : v)

typedef long long ll;
typedef long double ld;

const long long inf = 2e9;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    multiset<pair<ll, ll>> s;
    // Här har vi två sets: en "global" för att lagra intervall på allas intervall, och en "local" för att lagra intervall till en person

    rep(i, 0, n)
    {
        ll m;
        cin >> m;
        set<pair<ll, ll>> intervals;
        rep(j, 0, m)
        {
            ll l, r;
            cin >> l >> r;
            intervals.emplace(l, r);
        }
        ll cur_l = -inf;
        ll cur_r = -inf;
        // Vi har cur_l och cur_r som säger oss vad ändpunkterna på det intervall som vi bygger är

        trav(interval, intervals)
        {
            if (interval.first > cur_r)
            {
            // Det här betyder att nästa intervall kommer att börja efer att vår intervall slutar. Därför kan vi inte slå ihop felr intervall till
            // vår intervall och vi lägger bara det till "global_intervals"
                if (cur_l != -inf)
                {
                // Vi lägger till "(cur_l, -1)" och sedan gör "cur -= a.second" istället för att lägga till "(cur_l,1)"
                // Då när vi sorterar så vill vi att vi ska lägga till 1 till svaret innan vi tar bort en 1 om ett intervall i global_intervals
                // börjar vid cur_l och en anna slutar vid cur_l, därför lägger vi till "(cur_l, -1)" så att det vi ska lägga till hamnar först när vi sorterar
                // Exmepel: om vi har intervallet [1,2] hos person 1 och intervallet [2,3] hos person 2 då vill vi att det ska se ut såi setet som lagrar
                // globala intervall: lägg till, lägg till , ta bort, ta bort. Om vi lägger till (cur_l, 1) så får vi: lägg till ,ta bort, lägg till, ta bort
                // och svaret blir 1, vilket är fel
                    s.emplace(cur_l, -1);
                    s.emplace(cur_r, 1);
                }
                cur_l = interval.first;
                cur_r = interval.second;
            }
            else{
            // Om nästa intervall börjar innan vår intervall slutar då kan vi bara slå intervallen ihop till ett intervall
                cur_r = max(cur_r, interval.second);
            }
        }
        s.emplace(cur_l, -1);
        s.emplace(cur_r, 1);
    }
    ll ans = 0;
    ll cur = 0;
    trav(a, s)
    {
        cur -= a.second;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
