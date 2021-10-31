#!/usr/bin/python3

n = int(input())
# Här har vi två listor: en "global" för att lagra intervall på allas intervall, och en "local" för att lagra intervall till en person
global_intervals = []
for i in range(n):
    inpt = input().split()
    local_intervals = []
    i = 1
    while i < len(inpt):
        a = int(inpt[i])
        i += 1
        b = int(inpt[i])
        i += 1
        local_intervals.append((a, b))
    local_intervals.sort()
    # Vi har cur_l och cur_r som säger oss vad ändpunkterna på det intervall som vi bygger är
    cur_l = -1
    cur_r = -1
    for interval in local_intervals:
        if cur_r < interval[0]:
            # Det här betyder att nästa intervall kommer att börja efer att vår intervall slutar. Därför kan vi inte slå ihop felr intervall till
            # vår intervall och vi lägger bara det till "global_intervals"
            if cur_r != -1:
                # Vi lägger till "(cur_l, -1)" och sedan gör "cur -= a[1]" istället för att lägga till "(cur_l,1)"
                # Då när vi sorterar så vill vi att vi ska lägga till 1 till svaret innan vi tar bort en 1 om ett intervall i global_intervals
                # börjar vid cur_l och en anna slutar vid cur_l, därför lägger vi till "(cur_l, -1)" så att det vi ska lägga till hamnar först när vi sorterar
                # Exmepel: om vi har intervallet [1,2] hos person 1 och intervallet [2,3] hos person 2 då vill vi att det ska se ut så
                # i golobal_intervalls: lägg till, lägg till , ta bort, ta bort. Om vi lägger till (cur_l, 1) så får vi: lägg till ,ta bort, lägg till, ta bort
                # och svaret blir 1, vilket är fel
                global_intervals.append((cur_l, -1))
                global_intervals.append((cur_r, 1))
            cur_l = interval[0]
            cur_r = interval[1]
        else:
            # Om nästa intervall börjar innan vår intervall slutar då kan vi bara slå intervallen ihop till ett intervall
            cur_r = max(cur_r, interval[1])
    global_intervals.append((cur_l, -1))
    global_intervals.append((cur_r, 1))
ans = 0
cur = 0
global_intervals.sort()
for a in global_intervals:
    cur -= a[1]
    ans = max(ans, cur)
print(ans)
