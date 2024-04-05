# def find(x):
#     if x == par[x]:
#         return x
#     return par[x] = find(par[x])

class UF:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self,x,y):
        a = self.find(x)
        b = self.find(y)
        if a != b:
            self.parent[b] = a

li = [4,2,6,2]
uf = UF(305)
for val in li:
    i = 2
    n = val
    while i * i <= n:
        if n % i ==0:
            if uf.find(val)!=uf.find(i):
                uf.union(val, i)
            while n % i == 0:
                n //= i
        i += 1
    if n > 1 and uf.find(val)!=uf.find(n):
       uf.union(val,n)

num = list(li)
num.sort()

for i in range(len(li)):
    if li[i] != num[i] and uf.find(li[i]) != uf.find(num[i]):
        print('No')
        exit()
print("Yes")
    