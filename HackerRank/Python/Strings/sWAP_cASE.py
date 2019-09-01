def swap_case(line):
    swapLine = ""
    for i in range(0, len(line)):
        if line[i].isalpha():
            if line[i].isupper():
                swapLine += str(line[i]).lower()
            else:
                swapLine += str(line[i]).upper()
        else:
            swapLine += str(line[i])
    return swapLine

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
