def combine(m, n):
    a = len(m)
    c = ''
    count = 0
    for i in range(a):
        if(m[i] == n[i]):
            c += m[i]
        elif(m[i] != n[i]):
            c += '-'
            count += 1

    if(count > 1):
        return None
    else:
        return c


def find_prime_implicants(data):
    newList = list(data)
    size = len(newList)
    IM = []
    im = []
    im2 = []
    mark = [0]*size
    m = 0
    for i in range(size):
        for j in range(i+1, size):
            c = combine( str(newList[i]), str(newList[j]) )
            if c != None:
                im.append(str(c))
                mark[i] = 1
                mark[j] = 1
            else:
                continue

    mark2 = [0]*len(im)
    for p in range(len(im)):
        for n in range(p+1, len(im)):
            if( p != n and mark2[n] == 0):
                if( im[p] == im[n]):
                    mark2[n] = 1


    for r in range(len(im)):
        if(mark2[r] == 0):
            im2.append(im[r])

    for q in range(size):
        if( mark[q] == 0 ):
            IM.append( str(newList[q]) )
            m = m+1

    if(m == size or size == 1):
        return IM
    else:
        return IM + find_prime_implicants(im2)


minterms = set(['1101', '1100', '1110', '1111', '1010', '0011', '0111', '0110'])

minterms2 = set(['0000', '0100', '1000', '0101', '1100', '0111', '1011', '1111'])

minterms3 = set(['0001', '0011', '0100', '0110', '1011', '0000', '1000', '1010', '1100', '1101'])

minterms4 = set(['1000','0111'])

minterms5 = set(['0000', '0100', '1000', '1010', '1011', '1100','1101', '1111'])
print 'PI(s):', find_prime_implicants(minterms)

print 'PI2(s):', find_prime_implicants(minterms2)

print 'PI3(s):', find_prime_implicants(minterms3)

print (find_prime_implicants(minterms5))