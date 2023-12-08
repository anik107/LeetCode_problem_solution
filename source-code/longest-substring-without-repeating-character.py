# Anik Mahmud
s = input()
i=0
j=0
res=0
n=len(s)
disc = {}

while i<n and j<n:
    if disc.get(s[i],0)==0:
        res=max(res,i-j+1)
        disc[s[i]]=1
        i+=1
    else:
        disc[s[j]]-=1
        j+=1
print(res)