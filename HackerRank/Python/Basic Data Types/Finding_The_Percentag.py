student = int(input())
mdsMap = {}
for i in range(0,student):
    arr = str(input()).split(' ')
    average = 0.0
    for j in range(1, 4):
        average += float(arr[j])
    average /= 3.0
    mdsMap.update({arr[0]: average})

from sys import stdin
for line in stdin.readlines():
    name = str(line).strip()
    print("{0:.2f}".format(mdsMap[name]))