mainSet = set(map(int, str(input()).split()))
result = True
for i in range(0, int(input())):
    tempSet = set(map(int, str(input()).split()))
    if not result:
        continue
    if len(tempSet.intersection(mainSet)) != len(tempSet):
        result = False
    if len(mainSet.difference(tempSet)) == 0:
        result = False
print(result)
