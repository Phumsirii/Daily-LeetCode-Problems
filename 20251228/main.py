class Solution(object):
    def countNegatives(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        currentRow = m - 1
        currentCol = 0
        ans = 0
        while currentRow >= 0:
            while currentCol < n and grid[currentRow][currentCol] >= 0:
                currentCol += 1
            ans += n - currentCol
            currentRow -= 1
        return ans