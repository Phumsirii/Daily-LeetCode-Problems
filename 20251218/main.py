import numpy as np

class Solution(object):
    def maxProfit(self, prices, strategy, k):
        """
        :type prices: List[int]
        :type strategy: List[int]
        :type k: int
        :rtype: int
        """
        pricesNumpy = np.array(prices)
        strategyNumpy = np.array(strategy)
        profit = np.dot(pricesNumpy, strategyNumpy)
        length = len(prices)
        gainIfZero = -strategyNumpy * prices
        gainIfOne = (1 - strategyNumpy) * prices
        currentChange = np.sum(gainIfZero[: k // 2] + gainIfOne[k // 2: k])
        maxChange = max(0, currentChange)
        for i in range(length - k):
            currentChange += gainIfZero[i + k // 2]
            currentChange -= gainIfZero[i]
            currentChange += gainIfOne[i + k]
            currentChange -= gainIfOne[i + k // 2]
            maxChange = max(maxChange, currentChange)
        return profit + maxChange