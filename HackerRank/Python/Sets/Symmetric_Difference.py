m = int(input())
lista = list(map(int, input().split()))
setA = set(lista)
n = int(input())
lista = list(map(int, input().split()))
setB = set(lista)
ans = list(setA.difference(setB)) + list(setB.difference(setA))
ans.sort()
for val in ans:
    print(val)
