def print_rangoli(size):
    charList = [chr(c) for c in range(96, 97+26)]
    width = (size*2-1) + (size*2-2)

    lineFormat = "{0:-^"+str(width)+"}"
    for i in range(1, size+1):
        fList = charList[(size+1)-i:size+1]
        rList = charList[(size+1)-i:size+1]
        rList.reverse()
        pattern = "-".join(rList[:-1]+fList)
        print(lineFormat.format(pattern))
    for i in range(size-1, 0,-1):
        fList = charList[(size+1)-i:size+1]
        rList = charList[(size+1)-i:size+1]
        rList.reverse()
        pattern = "-".join(rList[:-1]+fList)
        print(lineFormat.format(pattern))

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
