groups = int(input())
values = list(map(int, str(input()).split()))
unique = {}
for val in values:
    if val in unique.keys():
        unique[val] += 1
    else:
        unique[val] = 1
for key in unique.keys():
    if unique[key] != groups:
        print(key)
        break
