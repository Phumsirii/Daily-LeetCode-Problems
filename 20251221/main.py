class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        rows = len(strs)
        cols = len(strs[0])
        strictlySorted = [False] * rows
        ans = 0
        for col in range(cols):
            mustDelete = False
            for row in range(1, rows):
                if not strictlySorted[row] and strs[row][col] < strs[row - 1][col]:
                    mustDelete = True
                    break
            if mustDelete:
                ans += 1
            else:
                for row in range(1, rows):
                    if strs[row][col] > strs[row - 1][col]:
                        strictlySorted[row] = True
        return ans