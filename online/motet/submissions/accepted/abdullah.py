n = int(input())
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
    cur_l = -1
    cur_r = -1
    for interval in local_intervals:
        if cur_r < interval[0]:
            if cur_r != -1:
                global_intervals.append((cur_l, -1))
                global_intervals.append((cur_r, 1))
            cur_l = interval[0]
            cur_r = interval[1]
        else:
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

