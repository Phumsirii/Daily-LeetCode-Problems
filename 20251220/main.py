class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        noOfStrings = len(strs)
        stringsLength = len(strs[0])
        ans = 0
        for col in range(stringsLength):
            for row in range(1, noOfStrings):
                if strs[row][col] < strs[row - 1][col]:
                    ans += 1
                    break
        return ans