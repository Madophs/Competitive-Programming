def merge_the_tools(string, k):
    arr = [False] * 26
    ans = "" 
    for i in range(0, len(string), k):
        ans = ""
        arr = [False] * 26
        for j in range(i, i+k):
            index = ord(string[j]) - ord('A')
            if not arr[index]:
                arr[index] = True
                ans += string[j]
        print(ans)




if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
