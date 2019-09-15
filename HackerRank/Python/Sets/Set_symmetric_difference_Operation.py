students = int(input())
englishSet = set(map(int, str(input()).split(' ')))
students = int(input())
frenchSet = set(map(int,str(input()).split(' ')))
print(len(englishSet.symmetric_difference(frenchSet)))

