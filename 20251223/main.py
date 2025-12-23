class Solution(object):
    
    def oper(self, events, dp, eventNo, eventsLeft, endTime):
        if eventsLeft < 0 or eventNo < 0:
            return 0
        if dp[eventsLeft][eventNo] > -1:
            return dp[eventsLeft][eventNo]
        currentStartTime = events[eventNo][0]
        currentValue = events[eventNo][2]
        # not choosing this event
        ans = self.oper(events, dp, eventNo - 1, eventsLeft, endTime)
        idx = bisect.bisect_left(endTime, currentStartTime) - 1
        # we may also choose this event
        ans = max(ans, currentValue + self.oper(events, dp, idx, eventsLeft - 1, endTime))
        dp[eventsLeft][eventNo] = ans
        return ans
    
    def maxTwoEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        noOfEvents = len(events)
        events.sort(key=lambda x: x[1])
        endTime = [x[1] for x in events]
        dp = [[-1] * noOfEvents for _ in range(2)]
        return self.oper(events, dp, noOfEvents - 1, 1, endTime)