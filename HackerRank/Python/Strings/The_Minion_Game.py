import re

def isVocal(letter):
    if letter == 'A':
        return True
    if letter == 'E':
        return True
    if letter == 'I':
        return True
    if letter == 'O':
        return True
    if letter == 'U':
        return True
    return False

def minion_game(string):
    stuart = 0
    kevin = 0
    for i in range(0, len(string)):
        if isVocal(string[i]):
            kevin += len(string)-i
        else:
            stuart += len(string)-i
    if stuart == kevin:
        print("Draw")
    elif stuart > kevin:
       print("Stuart "+str(stuart))
    else:
        print("Kevin "+str(kevin))


