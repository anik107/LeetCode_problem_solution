from collections import deque
import math


n = int(input())
li = [i * i for i in range(1, int(math.sqrt(n) + 1))]

q = deque()
vis = [False] * (n + 1)
step = 0

q.append(n)

while q:
    sz = len(q)

    for _ in range(sz):
        top = q.popleft()
        if top == 0:
            print(step)
            break
        for val in li:
            if top - val < 0 or vis[top - val] == True:
                continue
            q.append(top - val)
            vis[top - val] = True
    step += 1

print(step)
