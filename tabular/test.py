
def remind(a, b, numVar):
    count = 0
    newNum = ''
    for i in range(numVar):
        if a[i] != b[i]:
            count += 1
    if count == 1:
        for i in range(numVar):
            if a[i] != b[i]:
                newNum += '-'
            else:
                newNum += a[i]

    return newNum

a = '000'
b = '101'

print(remind(a,b,3))