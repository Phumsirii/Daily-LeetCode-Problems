class Solution(object):
    def bestClosingTime(self, customers):
        """
        :type customers: str
        :rtype: int
        """
        yesCount = 0
        noOfCustomer = len(customers)
        for log in range(noOfCustomer):
            if customers[log] == 'Y':
                yesCount += 1
        noCount = noOfCustomer - yesCount
        minPenalty = noCount
        closingTime = noOfCustomer
        noCount = 0
        for log in range(noOfCustomer):
            newPenalty = noCount + yesCount
            if customers[log] == 'N':
                noCount += 1
            else:
                yesCount -= 1
            if (newPenalty < minPenalty) or (newPenalty == minPenalty and closingTime == noOfCustomer):
                minPenalty = newPenalty
                closingTime = log
        return closingTime