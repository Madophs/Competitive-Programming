line = str(input())
alnum = False
alpha = False
digit = False
lower = False
upper = False
for letter in line:
    if letter.isalnum():
        alnum = True
    if letter.isalpha():
        alpha = True
    if letter.isdigit():
        digit = True
    if letter.islower():
        lower = True
    if letter.isupper():
        upper = True
print(alnum)
print(alpha)
print(digit)
print(lower)
print(upper)

