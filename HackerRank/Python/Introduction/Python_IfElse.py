n = int(input())
if n & 1 :
    print("Weird")
else:
    if n in range(2,5):
        print("Not Weird")
    elif n in range(6,21):
        print("Weird")
    else:
        print("Not Weird")
