list = []
size = int(input())
line = ""
list = [ int(val) for val in str(input()).split(' ') ]
list.sort()
ans = list[size-1]
for val in range(size-1,-1,-1):
    if ans != list[val]:
        ans = list[val]
        break
print(ans)

"""
Cool editorial solutions for python2

#Solution 1

from collections import Counter
if __name__ == '__main__':
    n = int(raw_input())
    arr = Counter(map(int, raw_input().split())).keys()
    arr.sort()
    print arr[-2]

#Solution 2

from collections import Counter
if __name__ == '__main__':
    n = int(raw_input())
    arr = list(set(map(int, raw_input().split())))
    arr.sort()
    print arr[-2]

"""