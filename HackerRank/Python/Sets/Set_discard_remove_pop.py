elements = int(input())
elemSet = set(list(map(int, input().split())))
queries = int(input())
for i in range(0, queries):
    command = str(input()).split()
    if command[0] == "remove":
        elemSet.remove(int(command[1]))
    elif command[0] == "discard":
        elemSet.discard(int(command[1]))
    else:
        elemSet.pop()
totalSum = 0
for val in elemSet:
    totalSum += val
print(totalSum)

