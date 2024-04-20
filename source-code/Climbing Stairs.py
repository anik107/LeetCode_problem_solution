def solve(n)->int:
    if n<0:
        return 0
    if n==0:
        return 1
    if li[n]!=-1:
        return li[n]
    a=solve(n-1)
    b=solve(n-2)
    li[n]=a+b
    return li[n]

n=int(input())
li=list(map(lambda x:-1, range(100)))

print(solve(n))