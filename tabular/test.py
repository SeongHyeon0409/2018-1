def DtoB(num):
    if num == 1:
        return '1'
    elif num == 0:
        return '0'
    ans = ('')
    while True:
        if num % 2 == 0:
            ans += '0'
        else:
            ans += '1'
        num = int(num / 2)
        if num == 1:
            ans += '1'
            return ans[::-1]


def checkEpi(minterms,a,b):
    for i in minterms:
        flag = 0
        for j in range(len(i)):
            if i[j] == a[j] or i[j] == '-' or a[j] == '-':
                continue
            else:
                flag = 1
                break
        if flag == 0:
            b.append(i)


a = [0, 1, 2, 3, 4]

a = [DtoB(num) for num in a]

minterm = ['0000', '0100', '1000', '1010', '1011', '1100', '1101', '1111']

a = '10-0'
b = []

checkEpi(minterm,a,b)

aa = {'10-0': ['1000', '1010'], '101-': ['1010', '1011'], '1-11': ['1011', '1111'], '110-': ['1100', '1101'], '11-1': ['1101', '1111'], '--00': ['0000', '0100', '1000', '1100']}

for i in aa:
    print(len(aa[i]))
