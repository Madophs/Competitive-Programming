def average(array):
    uniqueHeights = set(array)
    totalSum = 0
    for i in uniqueHeights:
        totalSum += int(i)
    return totalSum / len(uniqueHeights)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
