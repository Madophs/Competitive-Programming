def drawDoor(n, m):
    pattern = ".|."
    lineFormat = "{0:-^"+str(m)+"s}"
    for i in range(1,n,2):
        print(lineFormat.format(pattern*i))
    print(lineFormat.format("WELCOME"))
    for i in range(n-2, 0,-2):
        print(lineFormat.format(pattern*i))

arr = [int(i) for i in input().split(' ')]
drawDoor(arr[0], arr[1])
