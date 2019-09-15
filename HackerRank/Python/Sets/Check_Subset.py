test = int(input())
while test > 0:
    setASize = int(input())
    setA = set(map(int, str(input()).split()))
    setBSize = int(input())
    setB = set(map(int, str(input()).split()))
    print((setASize == len(setA.intersection(setB))))
    test -= 1
