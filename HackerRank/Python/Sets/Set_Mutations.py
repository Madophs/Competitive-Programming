elements = int(input())
elementsSet = set(map(int, str(input()).split()))
queries = int(input())
while queries > 0:
    command, size = str(input()).split()
    newElements = set(map(int, str(input()).split()))
    if command == "intersection_update":
        elementsSet.intersection_update(newElements)
    elif command == "update":
        elementsSet.update(newElements)
    elif command == "difference_update":
        elementsSet.difference_update(newElements)
    else:
        elementsSet.symmetric_difference_update(newElements)
    queries -= 1
print(sum(elementsSet))
