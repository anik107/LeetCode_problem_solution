from collections import deque

def isValid(x,y):
    return 0<=x<len(heights) and 0<=y<len(heights[0])
 
def check(k):
    queue = deque()
    queue.append((0,0))
    visited = [[False]*101 for _ in range(101)]
    visited[0][0]=True

    while queue:
        cx, cy = queue.popleft()
        if cx==len(heights)-1 and cy==len(heights[0])-1:
            return True
        
        for dx_val, dy_val in zip(dx,dy):
            x, y = cx+dx_val, cy+dy_val
            if isValid(x,y) and not visited[x][y]:
                if abs(heights[x][y]-heights[cx][cy])<=k:
                    queue.append((x,y))
                    visited[x][y]=True
    return False




heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

lo = 0
hi = max(max(heights,key=max))


while lo<hi:
    mid = lo+(hi-lo)//2
    if check(mid):
        hi = mid
    else:
        lo = mid+1
    print(lo,hi)


