class Solution(object):
    def checkPowersOfThree(self, n):
        a=[]
        i=0
        while pow(3, i)<1e7:
            a.append(pow(3, i))
            i+=1
        for i in reversed(a):
            if n>=i:
                n-=i
            else:
                continue
        return n==0
        
