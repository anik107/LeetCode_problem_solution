def solve(i, j):
    global grid, dp

    if i >= len(grid) or j >= len(grid[0]):
        return float("inf")

    if i == len(grid) - 1 and j == len(grid[0]) - 1:
        return grid[i][j]

    if dp[i][j] != float("inf"):
        return dp[i][j]

    val1 = solve(i + 1, j)
    val2 = solve(i, j + 1)

    dp[i][j] = min(val1, val2) + grid[i][j]
    return dp[i][j]


grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
dp = [[float("inf")] * len(grid[0]) for _ in range(len(grid))]
print(dp)
print(solve(0, 0))
