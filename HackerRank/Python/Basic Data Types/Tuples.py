n = int(input())
values = str(input())
tup = ()
for val in values.split(' '):
    tmpTup = (int(val),)
    tup = tup +  tmpTup
print(hash(tup))
