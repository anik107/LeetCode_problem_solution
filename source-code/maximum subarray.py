class Solution:
    def maxSubArray(self, li: List[int]) -> int:
        tot=-1*sys.maxsize
        mx=0
        for val in li:
            mx=mx+val
            if mx>tot:
                tot=mx
            if mx<0:
                mx=0
        return tot