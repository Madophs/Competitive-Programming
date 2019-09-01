def print_formatted(number):
    width = str(len("{0:b}".format(number)))
    stringFormat = "{0:>"+width+"} {1:>"+width+"o} {2:"+width+"X} {3:>"+width+"b}"; 
    for i in range(1,n+1):
        print(stringFormat.format(i, i, i ,i))

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
