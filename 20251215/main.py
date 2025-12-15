class Solution(object):
    def getDescentPeriods(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        ans = n
        currentConsecutive = 1
        for i in range(n - 1):
            if prices[i] - 1 == prices[i + 1]:
                currentConsecutive += 1
            else:
                valToAdd = currentConsecutive * (currentConsecutive - 1)
                valToAdd /= 2
                print(valToAdd)
                ans += valToAdd
                currentConsecutive = 1
        valToAdd = currentConsecutive * (currentConsecutive - 1)
        valToAdd /= 2
        ans += valToAdd
        currentConsecutive = 0
        return ans