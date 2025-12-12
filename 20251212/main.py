class Solution(object):
    def countMentions(self, numberOfUsers, events):
        """
        :type numberOfUsers: int
        :type events: List[List[str]]
        :rtype: List[int]
        """
        lastTurnedOnline = [0] * numberOfUsers
        ans = [0] * numberOfUsers
        events.sort(key=lambda x: (int(x[1]), x[0] != 'OFFLINE'))
        for event in events:
            eventType = event[0]
            timeStamp = int(event[1])
            mentioned = event[2]
            if eventType == 'MESSAGE':
                if mentioned == 'ALL':
                    for i in range(numberOfUsers):
                        ans[i] += 1
                elif mentioned == 'HERE':
                    for i in range(numberOfUsers):
                        if lastTurnedOnline[i] <= timeStamp:
                            ans[i] += 1
                else:
                    mentionedUsers = [int(s[2::]) for s in mentioned.split(" ")]
                    for i in mentionedUsers:
                        ans[i] += 1
                        
            else:
                userId = int(mentioned)
                lastTurnedOnline[userId] = timeStamp + 60
                
        return ans
            