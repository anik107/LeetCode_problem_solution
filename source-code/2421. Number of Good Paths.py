from collections import Counter

vals = [1,3,2,1,3]
edges = [[0,1],[0,2],[2,3],[2,4]]
n=len(vals)
cnt = [Counter({vals[i]: 1}) for i in range(n)]
edges = sorted([max(vals[i], vals[j]),i,j] for i,j in edges)

par = list(range(n))


def find(x):
    if par[x]==x:
        return x
    par[x]=find(par[x])
    return par[x]

print(cnt)
print(edges)
res=0
for val,u,v in edges:
    u,v=find(u),find(v)
    print(u,v,'..............',val)
    startVal,endVal = cnt[u][val],cnt[v][val]
    res+=startVal*endVal
    par[v]=u
    cnt[u]=Counter({val: startVal+endVal})
print(res)
