arraySetSize, setSize = list(map(int, str(input()).split()))
arrayList = list(map(int, str(input()).split()))
setA = set(map(int, str(input()).split()))
setB = set(map(int, str(input()).split()))
happiness = 0
for val in arrayList:
    if val in setA:
        happiness += 1
    if val in setB:
        happiness -= 1
print(happiness)
