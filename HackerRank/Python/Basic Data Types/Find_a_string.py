def count_substring(string, sub_string):
    occurrences = 0
    for i in range(0, (len(string)-len(sub_string))+1):
        found = True
        for j in range (0, len(sub_string)):
            if(string[i+j] == sub_string[j]):
                continue
            found = False
            break
        if found:
            occurrences += 1
    return occurrences

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)
