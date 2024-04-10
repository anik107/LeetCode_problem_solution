n = 3
edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]]
queries = [[0,1,2],[0,2,5]]

query_with_indes = [[*query,i] for i, query in enumerate(queries)]
query_with_indes.sort(key=lambda x: x[2])

edgeList.sort(key=lambda x: x[2])

par = list(range(n))

rank = [1]*n

def find(n):
    if n == par[n]:
            return n
    par[n] = find(par[n])
    return par[n]

def union(x,y):
    x=find(x)
    y=find(y)
    if x==y:
        return False
    if rank[x] > rank[y]:
        par[y] = x
        rank[x] += rank[y]
    else:
        par[x] = y
        rank[y] += rank[x]
    
    return True

edges_index = 0
res = [False]*len(queries)
for p,q,limit,i in query_with_indes:
    while edges_index < len(edgeList) and edgeList[edges_index][2] < limit:
        union(edgeList[edges_index][0],edgeList[edges_index][1])
        edges_index+=1
    res[i] = find(p)==find(q)

print(res)

        
            
