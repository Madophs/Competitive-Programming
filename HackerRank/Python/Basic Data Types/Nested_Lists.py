students = int(input())
matrixList = []
for i in range(0,students):
    name = str(input())
    grade = float(input())
    matrixList.append([])
    matrixList[i].append(name)
    matrixList[i].append(grade)
import operator
matrixList = sorted(matrixList, key = operator.itemgetter(1,0))
minGrade = matrixList[0][1]
secondMinGrade = 99999999
for i in matrixList:
    if i[1] == matrixList[0][1]:
        continue
    elif secondMinGrade == 99999999:
        secondMinGrade = i[1]
    if secondMinGrade == i[1]:
        print(i[0])
    elif secondMinGrade != 99999999:
        break
