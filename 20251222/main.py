class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        rowsCount = len(strs)
        colsCount = len(strs[0])
        dp = [1] * colsCount
        for col in range(colsCount):
            for pre in range(col):
                if all(strs[r][pre] <= strs[r][col] for r in range(rowsCount)):
                    dp[col] = max(dp[col], dp[pre] + 1)
        return colsCount - max(dp)