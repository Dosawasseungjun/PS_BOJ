import datetime

a, b, c = map(int, input().split())
today = datetime.date(a, b, c)
d, f, g = map(int, input().split())
d_day = datetime.date(d, f, g)
k = d_day - today
if d - a > 1000 or (d - a == 1000 and (f > b or f == b and g >= c)): print("gg")
else : print("D-{0}".format(k.days))