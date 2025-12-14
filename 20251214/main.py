class Solution(object):
    def numberOfWays(self, corridor):
        """
        :type corridor: str
        :rtype: int
        """
        seat_count = corridor.count('S')
        if seat_count % 2 != 0 or seat_count == 0:
            return 0
        ans = 1
        plantCount = 0
        seatCount = seat_count
        for char in corridor:
            if char == 'S':
                seatCount -= 1
                if seatCount > 0 and seatCount != seat_count - 1 and seatCount % 2 == 1:
                    ans = (ans * (plantCount + 1)) % (10**9 + 7)
                elif seatCount % 2 == 0:
                    plantCount = 0
            else:
                plantCount += 1
        return ans