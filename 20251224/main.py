class Solution(object):
    def minimumBoxes(self, apple, capacity):
        """
        :type apple: List[int]
        :type capacity: List[int]
        :rtype: int
        """
        totalNoOfApples = sum(apple)
        capacity.sort()
        noOfBoxes = len(capacity)
        currentBox = noOfBoxes - 1
        while currentBox >= 0 and totalNoOfApples > 0:
            totalNoOfApples -= capacity[currentBox]
            currentBox -= 1
        return noOfBoxes - currentBox - 1