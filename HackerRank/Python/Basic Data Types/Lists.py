cycles = int(input())
lista = []
def printList():
    print("[",end='')
    for i in range(0, len(lista)):
        if i > 0:
                print(" ", end='')
        if i == len(lista)-1:
            print(lista[i],end='');
        else:
            print(lista[i],end=',');
    print("]")
while cycles > 0:
    command = str(input()).split(' ');
    if command[0] == "insert":
        lista.insert(int(command[1]), int(command[2]))
    elif command[0] == "append":
        lista.append(int(command[1]))
    elif command[0] == "remove":
        lista.remove(int(command[1]))
    elif command[0] == "sort":
        lista.sort()
    elif command[0] == "pop":
        lista.pop()
    elif command[0] == "reverse":
        lista.reverse()
    else:
        printList()
    cycles -= 1
