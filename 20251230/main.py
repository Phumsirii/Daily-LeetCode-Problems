class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = len(grid)
        cols = len(grid[0])
        ans = 0
        for row in range(rows - 2):
            for col in range(cols - 2):
                existence = [False] * 9
                failed = False
                for i in range(3):
                    for j in range(3):
                        if grid[row + i][col + j] > 9 or grid[row + i][col + j] < 1:
                            failed = True
                            break
                        if existence[grid[row + i][col + j] - 1]:
                            failed = True
                            break
                        existence[grid[row + i][col + j] - 1] = True
                    if failed:
                        break
                if failed:
                    continue
                rowSum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2]
                colSum = grid[row][col] + grid[row + 1][col] + grid[row + 2][col]
                diaSum1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]
                diaSum2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col]
                if rowSum != colSum or diaSum1 != diaSum2 or diaSum1 != rowSum:
                    continue
                if rowSum == grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2] and rowSum == grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2] and colSum == grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1] and colSum == grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2]:
                    ans += 1
        return ans