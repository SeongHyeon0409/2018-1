#2018.5.20
#20171656
#Digital Logic Design
#implement quine-mccluskey method

def DtoB(num):
    if num == 1:
        return '1'
    elif num == 0:
        return '0'
    ans = ''
    while True:
        if num % 2 == 0:
            ans += '0'
        else:
            ans += '1'
        num = num / 2
        if num == 1:
            ans += '1'
            return ans[::-1]

def DtoBPlus(n,variables):
    zero = '0' * (variables - len(n))
    return zero + n

def remindCount(a, b, numVar):
    count = 0
    for i in range(numVar):
        if a[i] != b[i]:
            count += 1
    return count

def remind(a, b, numVar):
    newNum = ''
    for i in range(numVar):
        if a[i] != b[i]:
            newNum += '-'
        else:
            newNum += a[i]
    return newNum

def minimize(minimizeF, numberOfvariables,size):

    minimizeF2 = [['0' for a in range(0)] for b in range(size)]
    temp = []

    for j in range(len(minimizeF)-1): # 0 1 2
        for i in range(len(minimizeF[j])): # 0,,,
            for k in range(len(minimizeF[j+1])): # 1 2 1
                if remindCount(minimizeF[j][i],minimizeF[j+1][k],numberOfvariables) == 1:
                    a = remind(minimizeF[j][i],minimizeF[j+1][k],numberOfvariables)
                    minimizeF2[j].append(a)
                    temp.append(a)

    return (minimizeF2, temp)

def quineMccluskey(inNumbers):
    ##error exception
    try:
        inputList = inNumbers.split(" ")
        inputList = map(int, inputList)
    except:
        print("Please check the input again.")
        return 0

    numberOfvariables = inputList[0]
    numberOfminterms = inputList[1]
    minterms = inputList[2:]

    ##error exception
    if numberOfminterms != len(minterms):
        print("please input the number of minterms %d ." %numberOfminterms)
        return 0

    if numberOfvariables<3 or numberOfvariables>6:
        print("Please input the number of variables 3 to 6.")
        return 0

    for i in minterms:
        if i >= 2 ** numberOfvariables:
            print("please input minterms smaller than %d ." %2 ** numberOfvariables)
            return 0
        elif i < 0:
            print("please input positive integer.")

    #degit to binary
    minterms = map(DtoB, minterms)
    minterms = [DtoBPlus(i, numberOfvariables) for i in minterms]

    print(minterms)

    size = numberOfvariables + 1

    #Group minterms according to the number of 1's in the minterm
    minimizeF = [['0' for a in range(0)] for b in range(size)]
    for i in minterms:
        minimizeF[i.count('1')].append(i)

    print (minimizeF)

    temp = [1]
    if not temp:
        print("ab")
    while(!temp):
        minimizeF2, temp = minimize(minimizeF,numberOfvariables,size-1)
        size -= 1

    print(minimizeF2)
    print(temp)

if __name__ == "__main__":
    # inNumbers = input("input[# of input variables][# of minterms ][minterm list] : ")
    inNumbers = "3 5 0 1 5 6 7"
    quineMccluskey(inNumbers)









