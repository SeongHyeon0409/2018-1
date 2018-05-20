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

def quineMccluskey(inNumbers):
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
    for i in minterms:
        if i >= 2 ** numberOfvariables:
            print("please input minterms smaller than %d ." %2 ** numberOfvariables)
            return 0
        elif i < 0:
            print("please input positive integer.")

    if numberOfminterms != len(minterms):
        print("please input the number of minterms %d ." %numberOfminterms)
        return 0

    #degit to binary
    minterms = map(DtoB, minterms)
    minterms = [DtoBPlus(i, numberOfvariables) for i in minterms]

    print(numberOfvariables)
    print(minterms)


if __name__ == "__main__":
    # inNumbers = input("input[# of input variables][# of minterms ][minterm list] : ")
    inNumbers = "3 5 0 1 5 6"
    quineMccluskey(inNumbers)









