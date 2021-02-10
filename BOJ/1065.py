N = int(input())
cnt = 0
a = b = c = 0

for i in range(1,N+1) :
    if i < 100 : 
        cnt += 1
        continue
    a = i%10
    b = (i//10)%10
    c = i//100
    if (a-b)==(b-c) :
        cnt += 1

print (cnt)