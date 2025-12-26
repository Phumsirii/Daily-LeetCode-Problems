class Solution(object):
    def maximumHappinessSum(self, happiness, k):
        """
        :type happiness: List[int]
        :type k: int
        :rtype: int
        """
        happiness.sort()
        noOfChildren = len(happiness)
        ans = 0
        for i in range(k):
            currentVal = happiness[noOfChildren - 1 - i] - i
            currentVal = max(currentVal, 0)
            ans += currentVal
        return ans