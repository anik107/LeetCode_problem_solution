import sys
def solve(n):
    if n <= 0:
            return 0
    if n == 1:
        return 1
    if n in mp:
        return mp[n]

    a2 = float('inf')
    a2 = (n % 3) + solve(n // 3)

    a1 = (n % 2) + solve(n // 2)

    mp[n] = min(a1, a2)+1
    return mp[n]
n=10
mp=dict()
print(solve(n))