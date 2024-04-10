n = 4
roads = [[0,1,2],[0,2,4],[2,3,7]]

for sublist in roads:
    # Iterate through each element in the sublist and subtract 1
    for i in range(len(sublist)-1):
        sublist[i] -= 1

roads.sort(key=lambda x: -x[2])

print(roads)

par = list(range(n))

rank = [1]*n


def find(n):
    if n == par[n]:
            return n
    par[n] = find(par[n])
    return par[n]

cnt = [0]*n

for u,v,w in roads:
      u=find(u)
      v=find(v)
      par[v]=u
      cnt[u]=w
if find(0)==find(n-1):
      print(cnt[find(n-1)])
    





