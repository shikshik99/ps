def self_num(n) :
    b = n
    while 1 :
        b += int(n)%10
        n /= 10
        if n == 0 :
            break
        if b>10000 :
            b = 0
            break
    return b
chk = []
for i in range(1,10002):
    chk.append(0)
for i in range(1,10001) :
    if chk[i] == 0 :
        print(i)
    chk[self_num(i)]= 1