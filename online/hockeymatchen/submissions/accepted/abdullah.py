saves_a,goals_a,shots_a,saves_b,goals_b,shots_b = [int(i) for i in input().split()]
if shots_a==0:saves_b=0,goals_a=0
elif shots_a!=-1 and saves_b!=-1: goals_a=shots_a-saves_b
elif shots_a!=-1 and goals_a!=-1: saves_b=shots_a-saves_b
elif goals_a!=-1 and saves_b!=-1: shots_a=goals_a+saves_b 
if shots_b==0:saves_a=0,goals_b=0
elif shots_b!=-1 and saves_a!=-1: goals_b=shots_b-saves_a
elif shots_b!=-1 and goals_b!=-1: saves_a=shots_b-saves_a
elif goals_b!=-1 and saves_a!=-1: shots_b=goals_b+saves_a 
print(saves_a,goals_a,shots_a,saves_b,goals_b,shots_b)